#include <gtest/gtest.h>
#include "sliding-window/1423_maximum_points_you_can_obtain_from_cards.hpp" // Strictly pathed and lowercased

TEST(MaximumPointsYouCanObtainfromCardsTest, ExampleTests) {
    Solution sol;
    
    // Example 1
    std::vector<int> cardPoints1 = {1, 2, 3, 4, 5, 6, 1};
    EXPECT_EQ(sol.maxScore(cardPoints1, 3), 12);
    
    // Example 2
    std::vector<int> cardPoints2 = {2, 2, 2};
    EXPECT_EQ(sol.maxScore(cardPoints2, 2), 4);
    
    // Example 3
    std::vector<int> cardPoints3 = {9, 7, 7, 9, 7, 7, 9};
    EXPECT_EQ(sol.maxScore(cardPoints3, 7), 55);
}

TEST(MaximumPointsYouCanObtainfromCardsTest, AdditionalTests) {
    Solution sol;
    
    // Take exactly one card from the ends (right is bigger)
    std::vector<int> cardPoints1 = {1, 100, 2, 50};
    EXPECT_EQ(sol.maxScore(cardPoints1, 1), 50);

    // Take exactly one card from the ends (left is bigger)
    std::vector<int> cardPoints2 = {100, 2, 50, 1};
    EXPECT_EQ(sol.maxScore(cardPoints2, 1), 100);

    // Single card case
    std::vector<int> cardPoints3 = {42};
    EXPECT_EQ(sol.maxScore(cardPoints3, 1), 42);
}