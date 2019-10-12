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

    TEST_F(GeameFieldTest, kickI1) {
        auto field = GameField();
        field.reset(10, 20);

        field.setBlock(0, 19);
        field.setBlock(1, 19);
        field.setBlock(7, 19);
        field.setBlock(8, 19);
        field.setBlock(9, 19);

        field.setBlock(0, 18);
        field.setBlock(1, 18);
        field.setBlock(2, 18);
        field.setBlock(5, 18);
        field.setBlock(6, 18);
        field.setBlock(7, 18);
        field.setBlock(8, 18);
        field.setBlock(9, 18);

        auto ss = std::stringstream{};
        ss << field;
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
                            "34|0000000000\n"
                            "35|0000000000\n"
                            "36|0000000000\n"
                            "37|0000000000\n"
                            "38|0000000000\n"
                            "39|1111100111\n"
                            "40|1110000011\n"
                            "41|1111111111\n"
                            "42|1111111111\n"
                            "43|1111111111\n"
                            "44|1111111111\n"
        );


        // field.paste(2, 17, getGem(GEMTYPE_I, Rotation::Left));
        //
        // "37|0000001000\n"
        // "38|0000001000\n"
        // "39|1111101111\n"
        // "40|1110001011\n"

        int x = 2;
        int y = 17;
        auto gem = getGem(GEMTYPE_I, Rotation::Reverse);
        EXPECT_TRUE(field.wallkickTest(x, y, gem, 1));
    }

    TEST_F(GeameFieldTest, kickI2) {
        auto field = GameField();
        field.reset(10, 20);

        field.setBlock(0, 19);
        field.setBlock(1, 19);
        field.setBlock(2, 19);
        field.setBlock(8, 19);
        field.setBlock(9, 19);

        field.setBlock(0, 18);
        field.setBlock(1, 18);
        field.setBlock(2, 18);
        field.setBlock(3, 18);
        field.setBlock(4, 18);
        field.setBlock(7, 18);
        field.setBlock(8, 18);
        field.setBlock(9, 18);

        auto ss = std::stringstream{};
        ss << field;
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
                            "34|0000000000\n"
                            "35|0000000000\n"
                            "36|0000000000\n"
                            "37|0000000000\n"
                            "38|0000000000\n"
                            "39|1110011111\n"
                            "40|1100000111\n"
                            "41|1111111111\n"
                            "42|1111111111\n"
                            "43|1111111111\n"
                            "44|1111111111\n"
        );


        // field.paste(2, 17, getGem(GEMTYPE_I, Rotation::Left));
        //
        // "37|0001000000\n"
        // "38|0001000000\n"
        // "39|1111011111\n"
        // "40|1101000111\n"

        int x = 5;
        int y = 17;
        auto gem = getGem(GEMTYPE_I, Rotation::Spawn);
        EXPECT_TRUE(field.wallkickTest(x, y, gem, 0));
    }

    TEST_F(GeameFieldTest, getAttack) {
        auto field = GameField();
        field.reset(10, 20);
        field.setBlock(0, 19);  // パフェにならないようにする

        field.combo = 0;
        field.b2b = 0;

        EXPECT_EQ(field.getAttack(0, 0), 0);
        EXPECT_EQ(field.getAttack(1, 0), 0);  // Single
        EXPECT_EQ(field.getAttack(2, 0), 1);  // Double
        EXPECT_EQ(field.getAttack(3, 0), 2);  // Triple
        EXPECT_EQ(field.getAttack(4, 0), 4);  // Tetris

        EXPECT_EQ(field.getAttack(1, 1), 2);  // TSS
        EXPECT_EQ(field.getAttack(2, 1), 4);  // TSD
        EXPECT_EQ(field.getAttack(3, 1), 6);  // TST

        // wallkick==2のとき、厳密には火力を確定できない
        EXPECT_EQ(field.getAttack(1, 2), 0);  // TSM
        EXPECT_EQ(field.getAttack(2, 2), 4);  // TSM Double  // ぷよテトでは1

        field.b2b = 1;

        EXPECT_EQ(field.getAttack(1, 1), 3);  // B2B TSS
        EXPECT_EQ(field.getAttack(2, 1), 5);  // B2B TSD
        EXPECT_EQ(field.getAttack(3, 1), 7);  // B2B TST

        // wallkick==2のとき、厳密には火力を確定できない
        EXPECT_EQ(field.getAttack(1, 2), 1);  // B2B TSM
        EXPECT_EQ(field.getAttack(2, 2), 5);  // B2B TSM Double  // ぷよテトでは2
    }
}
