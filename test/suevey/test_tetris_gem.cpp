#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "MisaMino/tetris_ai.h"

namespace survey {
    using namespace ::testing;
    using namespace ::AI;

    class GemTest : public ::testing::Test {
    };

    TEST_F(GemTest, num) {
        EXPECT_EQ(AI::getGem(GEMTYPE_NULL, 0).num, 0);
        EXPECT_EQ(AI::getGem(GEMTYPE_I, 0).num, 1);
        EXPECT_EQ(AI::getGem(GEMTYPE_T, 0).num, 2);
        EXPECT_EQ(AI::getGem(GEMTYPE_L, 0).num, 3);
        EXPECT_EQ(AI::getGem(GEMTYPE_J, 0).num, 4);
        EXPECT_EQ(AI::getGem(GEMTYPE_Z, 0).num, 5);
        EXPECT_EQ(AI::getGem(GEMTYPE_S, 0).num, 6);
        EXPECT_EQ(AI::getGem(GEMTYPE_O, 0).num, 7);
    }

    TEST_F(GemTest, getGemColH) {
        // ブロックがないとき 0
        // ブロックがあるとき 1以上になる
        // ミノの4x4領域の上端からの高さ (だと思われる)
        {
            // [0] ____
            // [1] XXXX
            // [2] ____
            // [3] ____
            auto type = GEMTYPE_I;
            auto rotation = Rotation::Spawn;
            EXPECT_EQ(AI::getGemColH(type, rotation, 0), 2);
            EXPECT_EQ(AI::getGemColH(type, rotation, 1), 2);
            EXPECT_EQ(AI::getGemColH(type, rotation, 2), 2);
            EXPECT_EQ(AI::getGemColH(type, rotation, 3), 2);
        }

        {
            // [0] ____
            // [1] ____
            // [2] XXXX
            // [3] ____
            auto type = GEMTYPE_I;
            auto rotation = Rotation::Reverse;
            EXPECT_EQ(AI::getGemColH(type, rotation, 0), 3);
            EXPECT_EQ(AI::getGemColH(type, rotation, 1), 3);
            EXPECT_EQ(AI::getGemColH(type, rotation, 2), 3);
            EXPECT_EQ(AI::getGemColH(type, rotation, 3), 3);
        }

        {
            auto type = GEMTYPE_I;
            auto rotation = Rotation::Left;
            EXPECT_EQ(AI::getGemColH(type, rotation, 0), 0);
            EXPECT_EQ(AI::getGemColH(type, rotation, 1), 4);
            EXPECT_EQ(AI::getGemColH(type, rotation, 2), 0);
            EXPECT_EQ(AI::getGemColH(type, rotation, 3), 0);
        }

        {
            auto type = GEMTYPE_I;
            auto rotation = Rotation::Right;
            EXPECT_EQ(AI::getGemColH(type, rotation, 0), 0);
            EXPECT_EQ(AI::getGemColH(type, rotation, 1), 0);
            EXPECT_EQ(AI::getGemColH(type, rotation, 2), 4);
            EXPECT_EQ(AI::getGemColH(type, rotation, 3), 0);
        }

        {
            auto type = GEMTYPE_S;
            auto rotation = Rotation::Spawn;
            EXPECT_EQ(AI::getGemColH(type, rotation, 0), 1);
            EXPECT_EQ(AI::getGemColH(type, rotation, 1), 2);
            EXPECT_EQ(AI::getGemColH(type, rotation, 2), 2);
            EXPECT_EQ(AI::getGemColH(type, rotation, 3), 0);
        }

        {
            auto type = GEMTYPE_S;
            auto rotation = Rotation::Reverse;
            EXPECT_EQ(AI::getGemColH(type, rotation, 0), 2);
            EXPECT_EQ(AI::getGemColH(type, rotation, 1), 3);
            EXPECT_EQ(AI::getGemColH(type, rotation, 2), 3);
            EXPECT_EQ(AI::getGemColH(type, rotation, 3), 0);
        }

        {
            auto type = GEMTYPE_S;
            auto rotation = Rotation::Left;
            EXPECT_EQ(AI::getGemColH(type, rotation, 0), 3);
            EXPECT_EQ(AI::getGemColH(type, rotation, 1), 2);
            EXPECT_EQ(AI::getGemColH(type, rotation, 2), 0);
            EXPECT_EQ(AI::getGemColH(type, rotation, 3), 0);
        }

        {
            auto type = GEMTYPE_S;
            auto rotation = Rotation::Right;
            EXPECT_EQ(AI::getGemColH(type, rotation, 0), 0);
            EXPECT_EQ(AI::getGemColH(type, rotation, 1), 3);
            EXPECT_EQ(AI::getGemColH(type, rotation, 2), 2);
            EXPECT_EQ(AI::getGemColH(type, rotation, 3), 0);
        }
    }

    TEST_F(GemTest, caseI) {
        {
            auto gem = AI::getGem(GEMTYPE_I, 0);
            EXPECT_EQ(gem.num, 1);
            EXPECT_EQ(gem.mod, 4);  // 回転後の状態の個数だと思われる。基本4。Oのみ1
            EXPECT_EQ(gem.spin, 0);
            ASSERT_THAT(gem.bitmap, ElementsAre(0, 15, 0, 0));
            EXPECT_EQ(gem.geth(), 4);  // getHeight()の略だと思われる。 必ず 4
            EXPECT_EQ(gem.getLetter(), 'I');
        }

        {
            auto gem = AI::getGem(GEMTYPE_O, 0);
            EXPECT_EQ(gem.num, 7);
            EXPECT_EQ(gem.mod, 1);  // Oのみ 1
            EXPECT_EQ(gem.spin, 0);
            ASSERT_THAT(gem.bitmap, ElementsAre(6, 6, 0, 0));
            EXPECT_EQ(gem.getLetter(), 'O');
        }
    }
}
