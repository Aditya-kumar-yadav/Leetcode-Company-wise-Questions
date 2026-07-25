#include <gtest/gtest.h>
#include "sliding-window/2461_maximum_sum_of_distinct_subarrays_with_length_k.hpp"

TEST(MaximumSumOfDistinctSubarraysWithLengthKTest, ExampleTests) {
    Solution sol;
    
    // Example 1
    std::vector<int> nums1 = {1, 5, 4, 2, 9, 9, 9};
    EXPECT_EQ(sol.maximumSubarraySum(nums1, 3), 15);
    
    // Example 2
    std::vector<int> nums2 = {4, 4, 4};
    EXPECT_EQ(sol.maximumSubarraySum(nums2, 3), 0);
}

TEST(MaximumSumOfDistinctSubarraysWithLengthKTest, AdditionalTests) {
    Solution sol;
    
    // No valid subarray because k is larger than unique consecutive elements
    std::vector<int> nums1 = {1, 2, 1, 2, 1};
    EXPECT_EQ(sol.maximumSubarraySum(nums1, 3), 0);

    // Exact length match with all distinct elements
    std::vector<int> nums2 = {10, 20, 30};
    EXPECT_EQ(sol.maximumSubarraySum(nums2, 3), 60);

    // Single element window
    std::vector<int> nums3 = {5, 3, 3, 10, 2};
    EXPECT_EQ(sol.maximumSubarraySum(nums3, 1), 10);
}