/* * ID: 55
 * Title: Jump Game
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Required for std::max

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        size_t maxReach = 0;
        
        // 1. Loop using size_t to match nums.size() and avoid warnings
        for (size_t i = 0; i < nums.size(); i++) {
            
            // If our current index is beyond our maximum reach, we are stuck
            if (i > maxReach) {
                return false;
            }
            
            // Cast nums[i] to size_t to avoid signed/unsigned mismatch in std::max
            maxReach = max(maxReach, i + static_cast<size_t>(nums[i]));
            
            // Early exit optimization: if we can already reach the end
            if (maxReach >= nums.size() - 1) {
                return true;
            }
        }
        
        // 2. Ensure default code path returns a value
        return true;
    }
};