#include "gtest/gtest.h"

#include "MisaMino/tetris_ai.h"
//#include "MisaMino/tetris_ai.cpp"

namespace survey {
    using namespace ::testing;
    using namespace ::AI;

    class TetrisAITest : public ::testing::Test {
    };

    TEST_F(TetrisAITest, constructor) {
        AI::Moving mov;
        mov.movs.push_back(Moving::MOV_DROP);

        EXPECT_EQ(mov.x, 0);
        EXPECT_EQ(mov.movs.size(), 0);
    }

    TEST_F(TetrisAITest, Evaluate) {
//        long long &clearScore, double &avg_height, const AI_Param& ai_param, const GameField& last_pool, const GameField& pool, int cur_num,
//        int curdepth,
//        int total_clear_att, int total_clears, int clear_att, int clears, signed char wallkick_spin,
//        int lastCombo, int t_dis, int upcomeAtt

        long long clearScore = 0;
        double avg_height = 0;
        auto param = AI_Param{};
        param.tspin = 1;

        auto field = GameField();
        field.reset(10, 20);
        field.setBlock(0, 19);
        field.setBlock(1, 19);
        field.setBlock(2, 19);
        field.setBlock(3, 19);
        field.setBlock(4, 19);
        field.setBlock(5, 19);
        field.setBlock(7, 19);
        field.setBlock(8, 19);
        field.setBlock(9, 19);

        field.setBlock(0, 18);
        field.setBlock(1, 18);
        field.setBlock(2, 18);
        field.setBlock(3, 18);
        field.setBlock(4, 18);
        field.setBlock(8, 18);
        field.setBlock(9, 18);

        std::cout << field << std::endl;

        int score = Evaluate(
               clearScore, avg_height, param, field, field, GEMTYPE_I, 0,
                0, 0, 0, 0, 0, 0, 0, 0
        );
        EXPECT_EQ(score, 0);
    }

    TEST_F(TetrisAITest, Evaluate2) {
//        long long &clearScore, double &avg_height, const AI_Param& ai_param, const GameField& last_pool, const GameField& pool, int cur_num,
//        int curdepth,
//        int total_clear_att, int total_clears, int clear_att, int clears, signed char wallkick_spin,
//        int lastCombo, int t_dis, int upcomeAtt

        long long clearScore = 0;
        double avg_height = 0;
        auto param = AI_Param{};
        param.tspin3 = 1;

        auto field = GameField();
        field.reset(10, 20);

        {
            int y = 20;
            field.setBlockDirect(0, y);
            field.setBlockDirect(2, y);
            field.setBlockDirect(3, y);
            field.setBlockDirect(4, y);
            field.setBlockDirect(5, y);
            field.setBlockDirect(6, y);
            field.setBlockDirect(7, y);
            field.setBlockDirect(8, y);
            field.setBlockDirect(9, y);
        }

        {
            int y = 19;
            field.setBlockDirect(0, y);
            field.setBlockDirect(2, y);
            field.setBlockDirect(3, y);
            field.setBlockDirect(4, y);
            field.setBlockDirect(5, y);
            field.setBlockDirect(6, y);
            field.setBlockDirect(7, y);
            field.setBlockDirect(8, y);
            field.setBlockDirect(9, y);
        }

        {
            int y = 18;
            field.setBlockDirect(0, y);
            field.setBlockDirect(1, y);
            field.setBlockDirect(2, y);
            field.setBlockDirect(3, y);
            field.setBlockDirect(4, y);
            field.setBlockDirect(5, y);
            field.setBlockDirect(6, y);
            field.setBlockDirect(7, y);
            field.setBlockDirect(8, y);
        }

        {
            int y = 17;
            field.setBlockDirect(0, y);
            field.setBlockDirect(2, y);
            field.setBlockDirect(3, y);
            field.setBlockDirect(4, y);
            field.setBlockDirect(5, y);
            field.setBlockDirect(6, y);
            field.setBlockDirect(7, y);
            field.setBlockDirect(8, y);
            field.setBlockDirect(9, y);
        }

        field.setBlockDirect(0, 16);
        field.setBlockDirect(0, 15);
        field.setBlockDirect(0, 14);
        field.setBlockDirect(1, 14);
        field.setBlockDirect(1, 16);
        field.setBlockDirect(3, 16);
        field.setBlockDirect(3, 15);
        field.setBlockDirect(3, 14);

        std::cout << field << std::endl;

        int score = Evaluate(
                clearScore, avg_height, param, field, field, GEMTYPE_I, 0,
                0, 0, 0, 0, 0, 0, 0, 0
        );
        EXPECT_EQ(score, 0);
    }

    TEST_F(TetrisAITest, EvaluateRen) {
//        long long &clearScore, double &avg_height, const AI_Param& ai_param, const GameField& last_pool, const GameField& pool, int cur_num,
//        int curdepth,
//        int total_clear_att, int total_clears, int clear_att, int clears, signed char wallkick_spin,
//        int lastCombo, int t_dis, int upcomeAtt

        long long clearScore = 0;
        double avg_height = 0;
        auto param = AI_Param{};
        param.strategy_4w = 1;

        auto field = GameField();
        field.reset(10, 20);

        {
            int y = 20;
            field.setBlockDirect(4, y);
            field.setBlockDirect(5, y);
        }

        std::cout << field << std::endl;

        int score = Evaluate(
                clearScore, avg_height, param, field, field, GEMTYPE_I, 0,
                0, 0, 0, 0, 0, 0, 0, 0
        );
        EXPECT_EQ(score, 0);
    }
}
