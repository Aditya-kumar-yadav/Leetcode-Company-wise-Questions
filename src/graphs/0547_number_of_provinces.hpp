/* * ID: 547
 * Title: Number of Provinces
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

class Solution {
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        std::size_t n = isConnected.size();
        std::vector<int> parent(n);
        std::iota(parent.begin(), parent.end(), 0);
        std::vector<int> rank(n, 0);

        auto find = [&](auto& self, int i) -> int {
            if (parent[i] == i)
                return i;
            return parent[i] = self(self, parent[i]);
        };

        auto union_sets = [&](int i, int j) -> void {
            int root_i = find(find, i);
            int root_j = find(find, j);
            if (root_i != root_j) {
                if (rank[root_i] < rank[root_j]) {
                    parent[root_i] = root_j;
                } else if (rank[root_i] > rank[root_j]) {
                    parent[root_j] = root_i;
                } else {
                    parent[root_j] = root_i;
                    rank[root_i]++;
                }
            }
        };

        for (std::size_t i = 0; i < n; ++i) {
            for (std::size_t j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    union_sets(static_cast<int>(i), static_cast<int>(j));
                }
            }
        }

        int provinces = 0;
        for (std::size_t i = 0; i < n; ++i) {
            if (parent[i] == static_int_cast(int, i) || parent[i] == static_cast<int>(i)) {
                provinces++;
            }
        }

        return provinces;
    }
};