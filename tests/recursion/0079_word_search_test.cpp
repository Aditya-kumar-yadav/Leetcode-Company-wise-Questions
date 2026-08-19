#include <gtest/gtest.h>
#include "recursion/0079_word_search.hpp" // Strictly pathed and lowercased

TEST(WordSearchTest, StandardTestCases) {
    Solution sol;
    std::vector<std::vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    
    // LeetCode Example 1
    EXPECT_TRUE(sol.exist(board, "ABCCED"));
    
    // LeetCode Example 2
    EXPECT_TRUE(sol.exist(board, "SEE"));
    
    // LeetCode Example 3 (Fails because it tries to reuse the 'B' or 'C')
    EXPECT_FALSE(sol.exist(board, "ABCB"));
}

TEST(WordSearchTest, SingleCellBoard) {
    Solution sol;
    std::vector<std::vector<char>> board = {
        {'a'}
    };
    
    // Exact match
    EXPECT_TRUE(sol.exist(board, "a"));
    
    // Wrong letter
    EXPECT_FALSE(sol.exist(board, "b"));
    
    // Word is longer than the board itself
    EXPECT_FALSE(sol.exist(board, "aa"));
}

TEST(WordSearchTest, PreventCellReuse) {
    Solution sol;
    std::vector<std::vector<char>> board = {
        {'A', 'B', 'A'},
        {'B', 'A', 'B'}
    };
    
    // Valid paths
    EXPECT_TRUE(sol.exist(board, "ABA"));
    EXPECT_TRUE(sol.exist(board, "ABAB"));
    
    // Invalid: The word requires reusing a cell we just visited
    EXPECT_FALSE(sol.exist(board, "ABABAAB"));
}

TEST(WordSearchTest, EmptyBoard) {
    Solution sol;
    std::vector<std::vector<char>> board = {};
    
    // Should safely return false without segfaulting
    EXPECT_FALSE(sol.exist(board, "A"));
}