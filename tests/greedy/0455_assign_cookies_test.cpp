#include <gtest/gtest.h>
#include "greedy/0455_assign_cookies.hpp" 

using namespace std;

TEST(AssignCookiesTest, DefaultTest) {
    Solution sol;
    
    // Test Case 1: Standard case (LeetCode Example 1)
    // Only one cookie is big enough
    vector<int> g1 = {1, 2, 3};
    vector<int> s1 = {1, 1};
    EXPECT_EQ(sol.findContentChildren(g1, s1), 1);
    
    // Test Case 2: Standard case (LeetCode Example 2)
    // Both children can get a cookie
    vector<int> g2 = {1, 2};
    vector<int> s2 = {1, 2, 3};
    EXPECT_EQ(sol.findContentChildren(g2, s2), 2);
    
    // Test Case 3: Edge case - No cookies available
    vector<int> g3 = {1, 2, 3};
    vector<int> s3 = {};
    EXPECT_EQ(sol.findContentChildren(g3, s3), 0);
    
    // Test Case 4: Edge case - No children to feed
    vector<int> g4 = {};
    vector<int> s4 = {1, 2, 3};
    EXPECT_EQ(sol.findContentChildren(g4, s4), 0);
    
    // Test Case 5: Edge case - Cookies are all too small
    vector<int> g5 = {5, 6, 7};
    vector<int> s5 = {1, 2, 3};
    EXPECT_EQ(sol.findContentChildren(g5, s5), 0);
}