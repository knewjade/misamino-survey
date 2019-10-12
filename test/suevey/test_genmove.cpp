#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "MisaMino/main.h"
#include "MisaMino/tetris_ai.h"
#include "MisaMino/gamepool.h"

namespace survey {
    using namespace ::testing;
    using namespace ::AI;

    class GenMoveTest : public ::testing::Test {
    };

    TEST_F(GenMoveTest, getComboAttack) {
        AI::setComboList(std::vector{0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5});
        MisaBot.tetris.m_ai_param.combo = 30;
        EXPECT_EQ(getComboAttack(0), 0);
        EXPECT_EQ(getComboAttack(1), 0);
        EXPECT_EQ(getComboAttack(2), 1);
        EXPECT_EQ(getComboAttack(3), 1);
        EXPECT_EQ(getComboAttack(4), 2);
        EXPECT_EQ(getComboAttack(5), 2);
        EXPECT_EQ(getComboAttack(6), 3);
        EXPECT_EQ(getComboAttack(7), 3);
        EXPECT_EQ(getComboAttack(8), 4);
        EXPECT_EQ(getComboAttack(9), 4);
        EXPECT_EQ(getComboAttack(10), 4);
        EXPECT_EQ(getComboAttack(11), 5);
        EXPECT_EQ(getComboAttack(12), 5);
        EXPECT_EQ(getComboAttack(13), 5);
        EXPECT_EQ(getComboAttack(14), 5);
    }

    TEST_F(GenMoveTest, GenMoving) {
        auto field = GameField();
        field.reset(10, 20);
        field.setBlock(0, 19);

        auto movs = std::vector<MovingSimple>{};
        auto gem = getGem(GEMTYPE_I, Rotation::Spawn);
        GenMoving(field, movs, gem, 3, 1, false);
        EXPECT_EQ(movs.size(), 34);

        for (const auto &item : movs) {
            std::cout << item.x << ","
                      << item.y << ","
                      << (int) item.spin << ","
                      << (int) item.wallkick_spin << ","
                      << std::endl;
        }
    }

    TEST_F(GenMoveTest, FindPathMoving) {
        auto field = GameField();
        field.reset(10, 20);
        field.setBlock(0, 19);

        auto movs = std::vector<Moving>{};
        auto gem = getGem(GEMTYPE_I, Rotation::Spawn);
        FindPathMoving(field, movs, gem, 3, 1, false);
        EXPECT_EQ(movs.size(), 34);

//        for (const auto &item : movs) {
//            std::cout << item.x << ","
//                      << item.y << ","
//                      << (int) item.spin << ","
//                      << (int) item.wallkick_spin << ","
//                      << std::endl;
//        }
    }
}
