/* * ID: 37
 * Title: Sudoku Solver
 * Difficulty: Hard
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(std::vector<std::vector<char>>& board) {
        // Iterate through every cell on the board
        for (std::size_t i = 0; i < board.size(); ++i) {
            for (std::size_t j = 0; j < board[0].size(); ++j) {
                
                // If the cell is empty
                if (board[i][j] == '.') {
                    
                    // Try placing digits '1' to '9'
                    for (char c = '1'; c <= '9'; ++c) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            
                            // Recursively attempt to solve the rest of the board
                            if (solve(board)) {
                                return true; 
                            }
                            
                            // If it leads to a dead end, backtrack
                            board[i][j] = '.';
                        }
                    }
                    // If no digit 1-9 works here, this branch is invalid
                    return false; 
                }
            }
        }
        // If we loop through the entire board without returning false, it is solved
        return true; 
    }

    bool isValid(const std::vector<std::vector<char>>& board, std::size_t row, std::size_t col, char c) {
        for (std::size_t i = 0; i < 9; ++i) {
            // Check if the digit exists in the current row
            if (board[row][i] == c) {
                return false;
            }
            
            // Check if the digit exists in the current column
            if (board[i][col] == c) {
                return false;
            }
            
            // Check if the digit exists in the current 3x3 sub-box
            std::size_t boxRow = 3 * (row / 3) + i / 3;
            std::size_t boxCol = 3 * (col / 3) + i % 3;
            if (board[boxRow][boxCol] == c) {
                return false;
            }
        }
        return true;
    }
};