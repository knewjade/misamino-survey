#include "gtest/gtest.h"

#include "MisaMino/tetris.h"

namespace survey {
    using namespace ::testing;
    using namespace ::AI;

    class TetrisTest : public ::testing::Test {
    };

    TEST_F(TetrisTest, members) {
        auto tetris = Tetris();

        // Nextの生成がコメントアウトされているため、自分で行う
        // おそらくオリジナルが内部的にランダムに生成しようとしており、
        // AIとして使うには合わないためだと思われる
        tetris.m_next_num = 5;
        tetris.m_next[0] = getGem(GEMTYPE_I, 0);
        tetris.m_next[1] = getGem(GEMTYPE_T, 0);
        tetris.m_next[2] = getGem(GEMTYPE_L, 0);
        tetris.m_next[3] = getGem(GEMTYPE_J, 0);
        tetris.m_next[4] = getGem(GEMTYPE_Z, 0);


        // 実行準備完了
        EXPECT_EQ(tetris.m_cur.num, GEMTYPE_NULL);
        EXPECT_EQ(tetris.m_state, Tetris::STATE_READY);

        // 新しいミノの取り出し
        tetris.newpiece();

        EXPECT_EQ(tetris.m_cur.num, GEMTYPE_I);
        EXPECT_EQ(tetris.m_pool.m_hold, GEMTYPE_NULL);
        EXPECT_EQ(tetris.m_cur.spin, Rotation::Spawn);
        EXPECT_EQ(tetris.m_state, Tetris::STATE_MOVING);
        EXPECT_EQ(tetris.m_cur_x, 3);
        EXPECT_EQ(tetris.m_cur_y, 1);
        EXPECT_EQ(tetris.m_hold, false);
        EXPECT_EQ(tetris.wallkick_spin, 0);

        // 右移動
        {
            auto result = tetris.tryXMove(1);
            EXPECT_TRUE(result);
        }
        EXPECT_EQ(tetris.m_cur_x, 4);

        // 左回転
        {
            auto result = tetris.trySpin(1);
            EXPECT_TRUE(result);
        }
        EXPECT_EQ(tetris.m_cur.spin, Rotation::Left);
        EXPECT_EQ(tetris.wallkick_spin, 1);

        // 下移動
        {
            auto result = tetris.tryYMove(1);
            EXPECT_TRUE(result);
        }
        EXPECT_EQ(tetris.m_cur_y, 2);
        EXPECT_EQ(tetris.wallkick_spin, 0);

        // ホールド
        {
            auto result = tetris.tryHold();
            EXPECT_TRUE(result);
        }
        EXPECT_EQ(tetris.m_cur.num, GEMTYPE_T);
        EXPECT_EQ(tetris.m_pool.m_hold, GEMTYPE_I);
        EXPECT_EQ(tetris.m_cur.spin, Rotation::Spawn);
        EXPECT_EQ(tetris.m_state, Tetris::STATE_MOVING);
        EXPECT_EQ(tetris.m_cur_x, 3);
        EXPECT_EQ(tetris.m_cur_y, 1);
        EXPECT_EQ(tetris.m_hold, true);
    }
}
