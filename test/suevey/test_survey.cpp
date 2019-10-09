#include "gtest/gtest.h"

#include "core/survey.hpp"
#include "MisaMino/tetris_ai.h"
//#include "MisaMino/tetris_gem.h"

namespace survey {
    using namespace ::testing;

    class SurveyTest : public ::testing::Test {
    };

    TEST_F(SurveyTest, case1) {
        auto moving = AI::Moving();
        EXPECT_EQ(kValue, 10);

        auto gems = AI::getGem(0, 0);
        EXPECT_EQ(gems.num, 10);
    }
}
