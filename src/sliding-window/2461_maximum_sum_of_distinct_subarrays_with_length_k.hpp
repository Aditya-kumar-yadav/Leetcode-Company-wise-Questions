/* * ID: 2461
 * Title: Maximum Sum of Distinct Subarrays With Length K
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    long long maximumSubarraySum(std::vector<int>& nums, int k) {
        long long max_sum = 0;
        long long current_sum = 0;
        std::unordered_map<int, int> freq;
        std::size_t K = static_cast<std::size_t>(k);
        std::size_t n = nums.size();
        
        for (std::size_t i = 0; i < n; ++i) {
            // Add current element to the window
            current_sum += nums[i];
            freq[nums[i]]++;
            
            // If the window exceeds size k, remove the leftmost element
            if (i >= K) {
                int left_val = nums[i - K];
                current_sum -= left_val;
                freq[left_val]--;
                if (freq[left_val] == 0) {
                    freq.erase(left_val);
                }
            }
            
            // If window size is exactly k and all elements are distinct
            if (i >= K - 1 && freq.size() == K) {
                max_sum = std::max(max_sum, current_sum);
            }
        }
        
        return max_sum;
    }
};