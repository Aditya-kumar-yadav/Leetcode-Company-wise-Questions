/* * ID: 60
 * Title: Permutation Sequence
 * Difficulty: Hard
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        int fact = 1;
        std::string nums = "";
        
        for (int i = 1; i <= n; i++) {
            nums += std::to_string(i);
            if (i < n) fact *= i;
        }
        
        std::string ans = "";
        k -= 1; // 0-based indexing for the math
        
        while (n > 0) {
            int idx = k / fact;
            
            // Cast idx to std::size_t to safely access and erase from std::string
            ans += nums[static_cast<std::size_t>(idx)];
            nums.erase(static_cast<std::size_t>(idx), 1);
            
            n--;
            if (n > 0) {
                k %= fact;
                fact /= n;
            }
        }
        
        return ans;
    }
};