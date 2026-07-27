#include <gtest/gtest.h>
#include "sliding-window/1004_max_consecutive_ones_iii.hpp" // Strictly pathed and lowercased

TEST(MaxConsecutiveOnesIIITest, DefaultTest) {
    Solution sol;
    
    // Example 1: Standard case
    std::vector<int> nums1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    EXPECT_EQ(sol.longestOnes(nums1, 2), 6);
    
    // Example 2: Larger standard case
    std::vector<int> nums2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    EXPECT_EQ(sol.longestOnes(nums2, 3), 10);
    
    // Edge Case: Array with all 1s (no flips needed)
    std::vector<int> nums3 = {1, 1, 1, 1, 1};
    EXPECT_EQ(sol.longestOnes(nums3, 2), 5);
    
    // Edge Case: Array with all 0s, but k = 0 (can't flip any)
    std::vector<int> nums4 = {0, 0, 0, 0};
    EXPECT_EQ(sol.longestOnes(nums4, 0), 0);
    
    // Edge Case: Array with all 0s, with k > 0
    std::vector<int> nums5 = {0, 0, 0, 0};
    EXPECT_EQ(sol.longestOnes(nums5, 2), 2);
    
    // Edge Case: k is larger than the entire array length
    std::vector<int> nums6 = {1, 0, 1, 0};
    EXPECT_EQ(sol.longestOnes(nums6, 10), 4);
    
    // Edge Case: Single element (0), can flip
    std::vector<int> nums7 = {0};
    EXPECT_EQ(sol.longestOnes(nums7, 1), 1);
    
    // Edge Case: Single element (0), cannot flip
    std::vector<int> nums8 = {0};
    EXPECT_EQ(sol.longestOnes(nums8, 0), 0);
    
    // Edge Case: Alternating 1s and 0s
    std::vector<int> nums9 = {1, 0, 1, 0, 1, 0, 1};
    EXPECT_EQ(sol.longestOnes(nums9, 1), 3);
}