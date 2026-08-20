/* * ID: 455
 * Title: Assign Cookies
 * Difficulty: Easy
 */
#pragma once
#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort both the children's greed factors and the cookie sizes
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        size_t childIdx = 0;
        size_t cookieIdx = 0;
        
        // Iterate while we still have both children to check and cookies to give
        while (childIdx < g.size() && cookieIdx < s.size()) {
            // If the current cookie is big enough for the current child
            if (s[cookieIdx] >= g[childIdx]) {
                childIdx++; // The child is content, move to the next child
            }
            // Always move to the next cookie (whether we used it or it was too small)
            cookieIdx++;
        }
        
        // childIdx represents the total number of content children
        return static_cast<int>(childIdx); 
    }
};