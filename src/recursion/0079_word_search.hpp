/* * ID: 79
 * Title: Word Search
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>

class Solution {
    bool solve(const std::string& word, std::vector<std::vector<char>>& board, int x, int y, int m, int n, std::size_t i) {
        // Base case: If we matched all characters
        if (i == word.length()) return true;

        // Boundary checks and character matching
        // (x and y must be signed ints here so they can be checked for < 0)
        if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] != word[i]) {
            return false;
        }

        // Temporarily change character to mark as visited
        char temp = board[x][y];
        board[x][y] = '#';

        // Explore all 4 directions
        bool found = solve(word, board, x + 1, y, m, n, i + 1) ||
                     solve(word, board, x - 1, y, m, n, i + 1) ||
                     solve(word, board, x, y + 1, m, n, i + 1) ||
                     solve(word, board, x, y - 1, m, n, i + 1);

        // Backtrack: restore original character
        board[x][y] = temp;

        return found;
    }

public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        if (board.empty() || board[0].empty()) return false;

        // Store board dimensions as ints to pass into our DFS bounds checker
        int m = static_cast<int>(board.size());
        int n = static_cast<int>(board[0].size());
        
        // Use std::size_t for looping through container.size() safely
        for (std::size_t i = 0; i < board.size(); ++i) {
            for (std::size_t j = 0; j < board[0].size(); ++j) {
                // If the first character matches, trigger the DFS search
                if (board[i][j] == word[0]) {
                    if (solve(word, board, static_cast<int>(i), static_cast<int>(j), m, n, 0)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};