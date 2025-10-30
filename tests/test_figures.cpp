#include <gtest/gtest.h>
#include <sstream>

#include "Figure.h"
#include "Triangle.h"
#include "Hexagon.h"
#include "Octagon.h"

TEST(FigureTest, TriangleGeometricCenter)
{
    Triangle tri(1.0, 2.0, 3.0);
    auto center = tri.geometricCenter();
    EXPECT_DOUBLE_EQ(center.first, 1.0);
    EXPECT_DOUBLE_EQ(center.second, 2.0);
}

TEST(FigureTest, TriangleArea)
{
    Triangle tri(0.0, 0.0, 2.0);
    double expected_area = (3 * sqrt(3) / 4) * 2.0 * 2.0;
    EXPECT_DOUBLE_EQ(static_cast<double>(tri), expected_area);
}

TEST(FigureTest, TriangleCopy)
{
    Triangle tri1(1.0, 2.0, 3.0);
    Triangle tri2(tri1);
    EXPECT_TRUE(tri1 == tri2);
    EXPECT_DOUBLE_EQ(tri1.geometricCenter().first, tri2.geometricCenter().first);
    EXPECT_DOUBLE_EQ(tri1.geometricCenter().second, tri2.geometricCenter().second);
    EXPECT_DOUBLE_EQ(static_cast<double>(tri1), static_cast<double>(tri2));
}

TEST(FigureTest, TriangleMove)
{
    Triangle tri1(1.0, 2.0, 3.0);
    Triangle tri2 = std::move(tri1);
    EXPECT_DOUBLE_EQ(tri2.geometricCenter().first, 1.0);
    EXPECT_DOUBLE_EQ(tri2.geometricCenter().second, 2.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(tri2), (3 * sqrt(3) / 4) * 3.0 * 3.0);
}

TEST(FigureTest, TriangleStreamIO)
{
    Triangle tri;
    std::stringstream ss;
    ss << "1.0 2.0 3.0";
    ss >> tri;
    EXPECT_DOUBLE_EQ(tri.geometricCenter().first, 1.0);
    EXPECT_DOUBLE_EQ(tri.geometricCenter().second, 2.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(tri), (3 * sqrt(3) / 4) * 3.0 * 3.0);

    std::stringstream out;
    out << tri;
    std::string output = out.str();
    EXPECT_TRUE(output.find("Вершины треугольника") != std::string::npos);
}

TEST(FigureTest, HexagonGeometricCenter)
{
    Hexagon hex(3.0, 4.0, 5.0);
    auto center = hex.geometricCenter();
    EXPECT_DOUBLE_EQ(center.first, 3.0);
    EXPECT_DOUBLE_EQ(center.second, 4.0);
}

TEST(FigureTest, HexagonArea)
{
    Hexagon hex(0.0, 0.0, 2.0);
    double expected_area = (3 * sqrt(3) / 2) * 2.0 * 2.0;
    EXPECT_DOUBLE_EQ(static_cast<double>(hex), expected_area);
}

TEST(FigureTest, HexagonCopy)
{
    Hexagon hex1(3.0, 4.0, 5.0);
    Hexagon hex2(hex1);
    EXPECT_TRUE(hex1 == hex2);
    EXPECT_DOUBLE_EQ(hex1.geometricCenter().first, hex2.geometricCenter().first);
    EXPECT_DOUBLE_EQ(hex1.geometricCenter().second, hex2.geometricCenter().second);
    EXPECT_DOUBLE_EQ(static_cast<double>(hex1), static_cast<double>(hex2));
}

TEST(FigureTest, HexagonMove)
{
    Hexagon hex1(3.0, 4.0, 5.0);
    Hexagon hex2 = std::move(hex1);
    EXPECT_DOUBLE_EQ(hex2.geometricCenter().first, 3.0);
    EXPECT_DOUBLE_EQ(hex2.geometricCenter().second, 4.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(hex2), (3 * sqrt(3) / 2) * 5.0 * 5.0);
}

TEST(FigureTest, HexagonStreamIO)
{
    Hexagon hex;
    std::stringstream ss;
    ss << "3.0 4.0 5.0";
    ss >> hex;
    EXPECT_DOUBLE_EQ(hex.geometricCenter().first, 3.0);
    EXPECT_DOUBLE_EQ(hex.geometricCenter().second, 4.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(hex), (3 * sqrt(3) / 2) * 5.0 * 5.0);

    std::stringstream out;
    out << hex;
    std::string output = out.str();
    EXPECT_TRUE(output.find("Вершины шестиугольника") != std::string::npos);
}

TEST(FigureTest, OctagonGeometricCenter)
{
    Octagon oct(5.0, 6.0, 7.0);
    auto center = oct.geometricCenter();
    EXPECT_DOUBLE_EQ(center.first, 5.0);
    EXPECT_DOUBLE_EQ(center.second, 6.0);
}

TEST(FigureTest, OctagonArea)
{
    Octagon oct(0.0, 0.0, 2.0);
    double expected_area = 2 * (1 + sqrt(2)) * 2.0 * 2.0;
    EXPECT_DOUBLE_EQ(static_cast<double>(oct), expected_area);
}

TEST(FigureTest, OctagonCopy)
{
    Octagon oct1(5.0, 6.0, 7.0);
    Octagon oct2(oct1);
    EXPECT_TRUE(oct1 == oct2);
    EXPECT_DOUBLE_EQ(oct1.geometricCenter().first, oct2.geometricCenter().first);
    EXPECT_DOUBLE_EQ(oct1.geometricCenter().second, oct2.geometricCenter().second);
    EXPECT_DOUBLE_EQ(static_cast<double>(oct1), static_cast<double>(oct2));
}

TEST(FigureTest, OctagonMove)
{
    Octagon oct1(5.0, 6.0, 7.0);
    Octagon oct2 = std::move(oct1);
    EXPECT_DOUBLE_EQ(oct2.geometricCenter().first, 5.0);
    EXPECT_DOUBLE_EQ(oct2.geometricCenter().second, 6.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(oct2), 2 * (1 + sqrt(2)) * 7.0 * 7.0);
}

TEST(FigureTest, OctagonStreamIO)
{
    Octagon oct;
    std::stringstream ss;
    ss << "5.0 6.0 7.0";
    ss >> oct;
    EXPECT_DOUBLE_EQ(oct.geometricCenter().first, 5.0);
    EXPECT_DOUBLE_EQ(oct.geometricCenter().second, 6.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(oct), 2 * (1 + sqrt(2)) * 7.0 * 7.0);

    std::stringstream out;
    out << oct;
    std::string output = out.str();
    EXPECT_TRUE(output.find("Вершины восьмиугольника") != std::string::npos);
}

TEST(FigureTest, PolymorphicComparison)
{
    Triangle tri(1.0, 2.0, 3.0);
    Hexagon hex(1.0, 2.0, 3.0);
    EXPECT_FALSE(tri == hex);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}