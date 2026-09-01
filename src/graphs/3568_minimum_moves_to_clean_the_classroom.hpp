/* 
 * ID: 3568
 * Title: Minimum Moves to Clean the Classroom
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <queue> // Required for Breadth-First Search

class Solution {
public:
    int minMoves(std::vector<std::string>& classroom, int energy) {
        if (classroom.empty() || classroom[0].empty()) {
            return -1;
        }

        // Cast to int for boundary math, but we will use size_t for strict looping
        int m = static_cast<int>(classroom.size());
        int n = static_cast<int>(classroom[0].size());
        
        std::pair<int, int> start = {-1, -1};
        std::vector<std::pair<int, int>> litter;
        
        // 1. STRICT COMPILER REMINDER: using std::size_t for container iteration
        for (std::size_t i = 0; i < classroom.size(); ++i) {
            for (std::size_t j = 0; j < classroom[i].size(); ++j) {
                if (classroom[i][j] == 'S') {
                    start = {static_cast<int>(i), static_cast<int>(j)};
                } else if (classroom[i][j] == 'L') {
                    litter.push_back({static_cast<int>(i), static_cast<int>(j)});
                }
            }
        }
        
        std::size_t num_L = litter.size();
        if (num_L == 0) {
            return 0; // 2. Ensure all paths return a value
        }
        
        // Map each litter item to a specific bit index
        std::vector<std::vector<int>> litter_id(m, std::vector<int>(n, -1));
        for (std::size_t i = 0; i < litter.size(); ++i) {
            litter_id[litter[i].first][litter[i].second] = static_cast<int>(i);
        }
        
        int target_mask = (1 << num_L) - 1; 
        
        // visited[x][y][mask] = maximum energy remaining
        std::vector<std::vector<std::vector<int>>> visited(
            m, std::vector<std::vector<int>>(
                n, std::vector<int>(1 << num_L, -1)
            )
        );
        
        struct State {
            int x, y, mask, curr_energy, moves;
        };
        
        std::queue<State> q;
        q.push({start.first, start.second, 0, energy, 0});
        visited[start.first][start.second][0] = energy;
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            State curr = q.front();
            q.pop();
            
            if (curr.curr_energy == 0) {
                continue; 
            }
            
            for (int i = 0; i < 4; ++i) {
                int nx = curr.x + dx[i];
                int ny = curr.y + dy[i];
                
                // Bounds and obstacle check
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && classroom[nx][ny] != 'X') {
                    int next_energy = curr.curr_energy - 1;
                    int next_mask = curr.mask;
                    
                    if (classroom[nx][ny] == 'R') {
                        next_energy = energy;
                    } else if (classroom[nx][ny] == 'L') {
                        next_mask |= (1 << litter_id[nx][ny]);
                    }
                    
                    // Return immediately upon collecting the final piece of litter
                    if (next_mask == target_mask) {
                        return curr.moves + 1; // 2. Ensure all paths return a value
                    }
                    
                    // Only enqueue if this path offers strictly more energy for this state
                    if (next_energy > visited[nx][ny][next_mask]) {
                        visited[nx][ny][next_mask] = next_energy;
                        q.push({nx, ny, next_mask, next_energy, curr.moves + 1});
                    }
                }
            }
        }
        
        return -1; // 2. Ensure all paths return a value (triggers if impossible)
    }
};