#include <gtest/gtest.h>
#include "greedy/0055_jump_game.hpp" // Strictly pathed and lowercased
#include <vector>

using namespace std;

TEST(JumpGameTest, DefaultTest) {
    Solution sol;
    
    // Test Case 1: Standard win (LeetCode Example 1)
    vector<int> nums1 = {2, 3, 1, 1, 4};
    EXPECT_TRUE(sol.canJump(nums1)); 
    
    // Test Case 2: Standard loss due to trap (LeetCode Example 2)
    vector<int> nums2 = {3, 2, 1, 0, 4};
    EXPECT_FALSE(sol.canJump(nums2)); 
    
    // Test Case 3: Edge case - Array with only one element
    vector<int> nums3 = {0};
    EXPECT_TRUE(sol.canJump(nums3)); 
    
    // Test Case 4: Edge case - Exact jump to the end over zeroes
    vector<int> nums4 = {2, 0, 0};
    EXPECT_TRUE(sol.canJump(nums4)); 
    
    // Test Case 5: Edge case - Stuck immediately at the start
    vector<int> nums5 = {0, 2, 3};
    EXPECT_FALSE(sol.canJump(nums5));
    
    // Test Case 6: Edge case - Massive jump clears the whole board
    vector<int> nums6 = {10, 0, 0, 0, 0, 0};
    EXPECT_TRUE(sol.canJump(nums6));
}