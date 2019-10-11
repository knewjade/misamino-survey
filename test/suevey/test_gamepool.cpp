#include <sstream>

#include "gtest/gtest.h"

#include "MisaMino/gamepool.h"

namespace survey {
    using namespace ::testing;
    using namespace ::AI;

    class GeameFieldTest : public ::testing::Test {
    };

    TEST_F(GeameFieldTest, paste1) {
        auto field = GameField();
        auto height = 15;
        field.reset(10, height);

        // xはgemのbitmapの一番右を軸、フィールド右端を0として、左に移動する量を指定
        // yはgemのbitmapの一番下を軸、フィールド下端をh-1として、下に移動する量を指定 (0はbitmap一番下段しか表示されない)
        field.paste(0, height - 1, getGem(GEMTYPE_L, Rotation::Spawn));

        auto ss = std::stringstream{};
        ss << field;  //
        EXPECT_EQ(ss.str(), "\n"
                            "21|0000000000\n"
                            "22|0000000000\n"
                            "23|0000000000\n"
                            "24|0000000000\n"
                            "25|0000000000\n"
                            "26|0000000000\n"
                            "27|0000000000\n"
                            "28|0000000000\n"
                            "29|0000000000\n"
                            "30|0000000000\n"
                            "31|0000000000\n"
                            "32|0000000000\n"
                            "33|0000000000\n"
                            "34|0000000001\n"
                            "35|0000000111\n"
                            "36|1111111111\n"
                            "37|1111111111\n"
                            "38|1111111111\n"
                            "39|1111111111\n"
                            "40|1111111111\n"
                            "41|1111111111\n"
                            "42|1111111111\n"
                            "43|1111111111\n"
                            "44|1111111111\n"
        );
    }

    TEST_F(GeameFieldTest, paste2) {
        auto field = GameField();
        field.reset(10, 20);

        field.paste(0, 0, getGem(GEMTYPE_L, Rotation::Spawn));

        auto ss = std::stringstream{};
        ss << field;
        EXPECT_EQ(ss.str(), "\n"
                            "21|0000000111\n"
                            "22|0000000000\n"
                            "23|0000000000\n"
                            "24|0000000000\n"
                            "25|0000000000\n"
                            "26|0000000000\n"
                            "27|0000000000\n"
                            "28|0000000000\n"
                            "29|0000000000\n"
                            "30|0000000000\n"
                            "31|0000000000\n"
                            "32|0000000000\n"
                            "33|0000000000\n"
                            "34|0000000000\n"
                            "35|0000000000\n"
                            "36|0000000000\n"
                            "37|0000000000\n"
                            "38|0000000000\n"
                            "39|0000000000\n"
                            "40|0000000000\n"
                            "41|1111111111\n"
                            "42|1111111111\n"
                            "43|1111111111\n"
                            "44|1111111111\n"
        );
    }

    TEST_F(GeameFieldTest, paste3) {
        auto field = GameField();
        field.reset(10, 20);

        field.paste(0, 0, getGem(GEMTYPE_L, Rotation::Spawn));

        auto ss = std::stringstream{};
        ss << field;
        EXPECT_EQ(ss.str(), "\n"
                            "21|0000000111\n"
                            "22|0000000000\n"
                            "23|0000000000\n"
                            "24|0000000000\n"
                            "25|0000000000\n"
                            "26|0000000000\n"
                            "27|0000000000\n"
                            "28|0000000000\n"
                            "29|0000000000\n"
                            "30|0000000000\n"
                            "31|0000000000\n"
                            "32|0000000000\n"
                            "33|0000000000\n"
                            "34|0000000000\n"
                            "35|0000000000\n"
                            "36|0000000000\n"
                            "37|0000000000\n"
                            "38|0000000000\n"
                            "39|0000000000\n"
                            "40|0000000000\n"
                            "41|1111111111\n"
                            "42|1111111111\n"
                            "43|1111111111\n"
                            "44|1111111111\n"
        );
    }
}
