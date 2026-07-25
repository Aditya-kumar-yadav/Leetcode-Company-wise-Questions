/* * ID: 1423
 * Title: Maximum Points You Can Obtain from Cards
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int maxScore(std::vector<int>& cardPoints, int k) {
        int current_score = 0;
        int max_score = 0;
        std::size_t n = cardPoints.size();
        std::size_t K = static_cast<std::size_t>(k);
        
        // Initial window: Take all k cards from the beginning (left side)
        for (std::size_t i = 0; i < K; ++i) {
            current_score += cardPoints[i];
        }
        
        max_score = current_score;
        
        // Slide the window: Remove cards from the end of our left window 
        // and replace them with cards from the end of the array
        for (std::size_t i = 0; i < K; ++i) {
            current_score = current_score - cardPoints[K - 1 - i] + cardPoints[n - 1 - i];
            max_score = std::max(max_score, current_score);
        }
        
        return max_score;
    }
};