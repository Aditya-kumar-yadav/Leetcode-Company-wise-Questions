/* * ID: 3
 * Title: Longest Substring Without Repeating Characters
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Required for std::max

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Use an array to store the last seen index of each ASCII character
        std::vector<int> last_seen(128, -1);
        
        std::size_t max_len = 0;
        std::size_t left = 0;

        // Strictly using std::size_t for container.size() iteration
        for (std::size_t right = 0; right < s.size(); ++right) {
            unsigned char c = s[right];
            
            // If the character was seen within the current window, shrink the window
            if (last_seen[c] >= static_cast<int>(left)) {
                left = last_seen[c] + 1;
            }
            
            // Update the last seen index of the character
            last_seen[c] = static_cast<int>(right);
            
            // Calculate the current window size and update max_len
            max_len = std::max(max_len, right - left + 1);
        }

        // Guaranteed final return value, casted back to match LeetCode's int signature
        return static_cast<int>(max_len);
    }
};