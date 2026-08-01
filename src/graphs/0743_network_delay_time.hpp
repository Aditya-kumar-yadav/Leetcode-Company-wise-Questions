/* * ID: 743
 * Title: Network Delay Time
 * Difficulty: Medium
 */
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <queue>      // Required for std::priority_queue
#include <algorithm>  // Required for std::max
#include <utility>    // Required for std::pair

class Solution {
public:
    int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
        // Build adjacency list: node -> vector of {neighbor, weight}
        std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
        
        // Range-based for loop naturally avoids std::size_t warnings
        for (const auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }

        // Min-heap priority queue storing pairs of {current_distance, node}
        std::priority_queue<std::pair<int, int>, 
                            std::vector<std::pair<int, int>>, 
                            std::greater<std::pair<int, int>>> pq;
        
        // Distance array initialized to a large value representing infinity
        std::vector<int> dist(n + 1, 1e9);

        // Start from source node k
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            // Skip processing if we already found a shorter path to u
            if (d > dist[u]) continue;

            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Find the maximum time taken among all reachable nodes
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == 1e9) {
                return -1; // Code path returns immediately if any node is unreachable
            }
            maxTime = std::max(maxTime, dist[i]);
        }

        return maxTime; // Guaranteed final return value
    }
};