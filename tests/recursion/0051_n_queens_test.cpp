#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "recursion/0051_n_queens.hpp" // Strictly pathed and lowercased

TEST(NQueensTest, DefaultTest) {
    Solution sol;
    
    // Test case 1: N = 4
    std::vector<std::vector<std::string>> expected4 = {
        {".Q..",
         "...Q",
         "Q...",
         "..Q."},
        {"..Q.",
         "Q...",
         "...Q",
         ".Q.."}
    };
    EXPECT_EQ(sol.solveNQueens(4), expected4);

    // Test case 2: N = 1
    std::vector<std::vector<std::string>> expected1 = {
        {"Q"}
    };
    EXPECT_EQ(sol.solveNQueens(1), expected1);
}