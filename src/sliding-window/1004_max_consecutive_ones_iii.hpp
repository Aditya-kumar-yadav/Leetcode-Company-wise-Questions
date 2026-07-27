/* * ID: 1004
 * Title: Max Consecutive Ones III
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        std::size_t left = 0;
        int max_len = 0;
        int zero_count = 0;
        
        for (std::size_t right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                zero_count++;
            }
            
            // If we have flipped more than k zeros, shrink the window from the left
            while (zero_count > k) {
                if (nums[left] == 0) {
                    zero_count--;
                }
                left++;
            }
            
            // Calculate the valid window size
            int current_len = static_cast<int>(right - left + 1);
            max_len = std::max(max_len, current_len);
        }
        
        return max_len;
    }
};