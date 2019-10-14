#include "gtest/gtest.h"

#include "MisaMino/tetris_ai.h"

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
}
