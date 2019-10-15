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

        auto field = GameField();
        field.reset(10, 20);
        field.setBlock(0, 19);

        int score = Evaluate(
               clearScore, avg_height, param, field, field, GEMTYPE_I, 0,
                0, 0, 0, 0, 0, 0, 0, 0
        );
        EXPECT_EQ(score, 0);
    }
}
