/* * ID: 713
 * Title: Subarray Product Less Than K
 * Difficulty: Medium
 */
#pragma once
#include <vector>
#include <cstddef>

class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        // Since all nums[i] >= 1, the product can never be strictly less than k if k <= 1.
        if (k <= 1) {
            return 0;
        }
        
        int count = 0;
        long long product = 1; // Use long long to prevent overflow before division
        std::size_t left = 0;
        std::size_t n = nums.size();
        
        for (std::size_t right = 0; right < n; ++right) {
            product *= nums[right];
            
            // Shrink the window from the left if the product is too large
            while (product >= k && left <= right) {
                product /= nums[left];
                left++;
            }
            
            // The number of valid subarrays ending at 'right' is the size of the window
            count += (right - left + 1);
        }
        
        return count;
    }
};