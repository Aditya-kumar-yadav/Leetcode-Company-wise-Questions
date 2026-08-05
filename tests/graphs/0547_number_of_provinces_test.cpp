#include <gtest/gtest.h>
#include "graphs/0547_number_of_provinces.hpp" // Strictly pathed and lowercased

TEST(NumberofProvincesTest, DefaultTest) {
    Solution sol;
    
    std::vector<std::vector<int>> matrix1 = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    EXPECT_EQ(sol.findCircleNum(matrix1), 2);

    std::vector<std::vector<int>> matrix2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    EXPECT_EQ(sol.findCircleNum(matrix2), 3);

    std::vector<std::vector<int>> matrix3 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    EXPECT_EQ(sol.findCircleNum(matrix3), 1);

    std::vector<std::vector<int>> matrix4 = {
        {1}
    };
    EXPECT_EQ(sol.findCircleNum(matrix4), 1);
}