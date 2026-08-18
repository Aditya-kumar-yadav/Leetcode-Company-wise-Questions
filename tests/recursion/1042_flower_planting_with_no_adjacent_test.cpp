#include <gtest/gtest.h>
#include <vector>
#include "recursion/1042_flower_planting_with_no_adjacent.hpp" // Strictly pathed and lowercased

TEST(FlowerPlantingWithNoAdjacentTest, LeetCodeExamples) {
    Solution sol;
    
    // Test Case 1: Triangle graph
    int n1 = 3;
    std::vector<std::vector<int>> paths1 = {{1, 2}, {2, 3}, {3, 1}};
    std::vector<int> expected1 = {1, 2, 3};
    EXPECT_EQ(sol.gardenNoAdj(n1, paths1), expected1);

    // Test Case 2: Disconnected components
    int n2 = 4;
    std::vector<std::vector<int>> paths2 = {{1, 2}, {3, 4}};
    // The backtracking algorithm will assign colors in order 1, 2, 1, 2
    std::vector<int> expected2 = {1, 2, 1, 2};
    EXPECT_EQ(sol.gardenNoAdj(n2, paths2), expected2);

    // Test Case 3: Fully connected max degree graph (each node has 3 edges)
    int n3 = 4;
    std::vector<std::vector<int>> paths3 = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 3}, {2, 4}};
    std::vector<int> expected3 = {1, 2, 3, 4};
    EXPECT_EQ(sol.gardenNoAdj(n3, paths3), expected3);
}

TEST(FlowerPlantingWithNoAdjacentTest, EdgeCases) {
    Solution sol;
    
    // Test Case 4: No paths (all gardens isolated)
    int n4 = 4;
    std::vector<std::vector<int>> paths4 = {};
    std::vector<int> expected4 = {1, 1, 1, 1}; 
    EXPECT_EQ(sol.gardenNoAdj(n4, paths4), expected4);

    // Test Case 5: Linear graph (1-2-3-4)
    int n5 = 4;
    std::vector<std::vector<int>> paths5 = {{1, 2}, {2, 3}, {3, 4}};
    std::vector<int> expected5 = {1, 2, 1, 2}; 
    EXPECT_EQ(sol.gardenNoAdj(n5, paths5), expected5);
}