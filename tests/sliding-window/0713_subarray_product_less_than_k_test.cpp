#include <gtest/gtest.h>
#include "sliding-window/713_subarray_product_less_than_k.hpp"

TEST(SubarrayProductLessThanKTest, ExampleTests) {
    Solution sol;
    
    // Example 1
    std::vector<int> nums1 = {10, 5, 2, 6};
    EXPECT_EQ(sol.numSubarrayProductLessThanK(nums1, 100), 8);
    
    // Example 2
    std::vector<int> nums2 = {1, 2, 3};
    EXPECT_EQ(sol.numSubarrayProductLessThanK(nums2, 0), 0);
}

TEST(SubarrayProductLessThanKTest, AdditionalTests) {
    Solution sol;
    
    // k = 1 edge case (should be 0 since elements are >= 1)
    std::vector<int> nums1 = {1, 1, 1};
    EXPECT_EQ(sol.numSubarrayProductLessThanK(nums1, 1), 0);

    // All elements strictly greater than k
    std::vector<int> nums2 = {10, 20, 30};
    EXPECT_EQ(sol.numSubarrayProductLessThanK(nums2, 5), 0);

    // Array with a single element strictly less than k
    std::vector<int> nums3 = {5};
    EXPECT_EQ(sol.numSubarrayProductLessThanK(nums3, 10), 1);
}