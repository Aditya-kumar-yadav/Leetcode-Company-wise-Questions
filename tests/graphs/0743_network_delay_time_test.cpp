#include <gtest/gtest.h>
#include <vector>
#include "graphs/0743_network_delay_time.hpp" // Strictly pathed and lowercased

TEST(NetworkDelayTimeTest, LeetCodeExample1) {
    Solution sol;
    std::vector<std::vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4;
    int k = 2;
    EXPECT_EQ(sol.networkDelayTime(times, n, k), 2);
}

TEST(NetworkDelayTimeTest, LeetCodeExample2) {
    Solution sol;
    std::vector<std::vector<int>> times = {{1, 2, 1}};
    int n = 2;
    int k = 1;
    EXPECT_EQ(sol.networkDelayTime(times, n, k), 1);
}

TEST(NetworkDelayTimeTest, LeetCodeExample3_UnreachableNode) {
    Solution sol;
    std::vector<std::vector<int>> times = {{1, 2, 1}};
    int n = 2;
    int k = 2;
    // Node 1 cannot be reached from node 2
    EXPECT_EQ(sol.networkDelayTime(times, n, k), -1);
}

TEST(NetworkDelayTimeTest, DisconnectedGraph) {
    Solution sol;
    // Graph with two disconnected components: 1->2->3 and 4->5
    std::vector<std::vector<int>> times = {{1, 2, 4}, {2, 3, 2}, {4, 5, 1}};
    int n = 5;
    int k = 1;
    // Starting at 1, we can never reach 4 or 5
    EXPECT_EQ(sol.networkDelayTime(times, n, k), -1);
}