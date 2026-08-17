/* * ID: 51
 * Title: N-Queens
 * Difficulty: Hard
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> board(n, std::string(n, '.'));
        solve(0, n, board, result);
        return result;
    }

private:
    void solve(int row, int n, std::vector<std::string>& board, std::vector<std::vector<std::string>>& result) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            if (isValid(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(row + 1, n, board, result);
                board[row][col] = '.'; // Backtrack
            }
        }
    }

    bool isValid(const std::vector<std::string>& board, int row, int col, int n) {
        // Check current column above the current row
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        
        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    }
};