#include <gtest/gtest.h>
#include "graphs/3568_minimum_moves_to_clean_the_classroom.hpp" // Strictly pathed and lowercased

TEST(MinimumMovestoCleantheClassroomTest, Example1) {
    Solution sol;
    std::vector<std::string> classroom = {
        "S.", 
        "XL"
    };
    int energy = 2;
    // (0,0) -> (0,1) -> (1,1) = 2 moves
    EXPECT_EQ(sol.minMoves(classroom, energy), 2);
}

TEST(MinimumMovestoCleantheClassroomTest, ImpossibleToReach) {
    Solution sol;
    std::vector<std::string> classroom = {
        "S.X", 
        "XXL"
    };
    int energy = 10;
    // Litter is walled off by obstacles
    EXPECT_EQ(sol.minMoves(classroom, energy), -1);
}

TEST(MinimumMovestoCleantheClassroomTest, RequiresRecharge) {
    Solution sol;
    std::vector<std::string> classroom = {
        "S.R.L"
    };
    int energy = 2;
    // S -> . -> R (Energy goes 2 -> 1 -> 2)
    // R -> . -> L (Energy goes 2 -> 1 -> 0, target reached)
    // Total moves = 4
    EXPECT_EQ(sol.minMoves(classroom, energy), 4);
}

TEST(MinimumMovestoCleantheClassroomTest, OutOfEnergy) {
    Solution sol;
    std::vector<std::string> classroom = {
        "S...L"
    };
    int energy = 3;
    // Needs 4 moves but only has 3 energy and no rechargers
    EXPECT_EQ(sol.minMoves(classroom, energy), -1);
}

TEST(MinimumMovestoCleantheClassroomTest, NoLitter) {
    Solution sol;
    std::vector<std::string> classroom = {
        "S..", 
        "..."
    };
    int energy = 2;
    // No 'L' targets, should return 0 immediately
    EXPECT_EQ(sol.minMoves(classroom, energy), 0);
}