/* * ID: 1042
 * Title: Flower Planting With No Adjacent
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>

class Solution {
    bool valid(const std::vector<std::vector<int>>& adj, const std::vector<int>& color, int i, int node) {
        for (auto val : adj[node]) {
            if (color[val] == i) return false;
        }
        return true;
    }

    bool solve(int n, std::vector<std::vector<int>>& adj, std::vector<int>& color, int node, std::vector<int>& vec) {
        if (node == n + 1) return true;
        
        for (int i = 1; i <= 4; i++) {
            if (valid(adj, color, i, node)) {
                color[node] = i;
                vec.push_back(i);
                
                if (solve(n, adj, color, node + 1, vec)) return true;
                else {
                    color[node] = -1;
                    vec.pop_back();
                }
            }
        }
        return false;
    }

public:
    std::vector<int> gardenNoAdj(int n, std::vector<std::vector<int>>& paths) {
        std::vector<int> color(n + 1, -1);
        std::vector<int> vec;
        std::vector<std::vector<int>> adj(n + 1);
        
        for (const auto& val : paths) {
            adj[val[0]].push_back(val[1]);
            adj[val[1]].push_back(val[0]);
        }
        
        solve(n, adj, color, 1, vec);
        return vec;
    }
};