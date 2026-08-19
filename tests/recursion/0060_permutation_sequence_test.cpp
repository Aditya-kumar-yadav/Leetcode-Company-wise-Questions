#include <gtest/gtest.h>
#include "recursion/0060_permutation_sequence.hpp" // Strictly pathed and lowercased

TEST(PermutationSequenceTest, StandardTestCases) {
    Solution sol;
    
    // LeetCode Example 1
    EXPECT_EQ(sol.getPermutation(3, 3), "213");
    
    // LeetCode Example 2
    EXPECT_EQ(sol.getPermutation(4, 9), "2314");
    
    // LeetCode Example 3
    EXPECT_EQ(sol.getPermutation(3, 1), "123");
}

TEST(PermutationSequenceTest, EdgeCases) {
    Solution sol;
    
    // Smallest possible input
    EXPECT_EQ(sol.getPermutation(1, 1), "1");
    
    // First permutation for N=4
    EXPECT_EQ(sol.getPermutation(4, 1), "1234");
    
    // Last permutation for N=4 (4! = 24)
    EXPECT_EQ(sol.getPermutation(4, 24), "4321");
    
    // Max N, first permutation
    EXPECT_EQ(sol.getPermutation(9, 1), "123456789");
}