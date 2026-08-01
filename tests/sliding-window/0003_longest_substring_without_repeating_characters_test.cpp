#include <gtest/gtest.h>
#include <string>
#include "sliding-window/0003_longest_substring_without_repeating_characters.hpp" // Strictly pathed and lowercased

TEST(LongestSubstringWithoutRepeatingCharactersTest, LeetCodeExample1) {
    Solution sol;
    std::string s = "abcabcbb";
    EXPECT_EQ(sol.lengthOfLongestSubstring(s), 3);
}

TEST(LongestSubstringWithoutRepeatingCharactersTest, LeetCodeExample2) {
    Solution sol;
    std::string s = "bbbbb";
    EXPECT_EQ(sol.lengthOfLongestSubstring(s), 1);
}

TEST(LongestSubstringWithoutRepeatingCharactersTest, LeetCodeExample3) {
    Solution sol;
    std::string s = "pwwkew";
    EXPECT_EQ(sol.lengthOfLongestSubstring(s), 3);
}

TEST(LongestSubstringWithoutRepeatingCharactersTest, EmptyString) {
    Solution sol;
    std::string s = "";
    EXPECT_EQ(sol.lengthOfLongestSubstring(s), 0);
}

TEST(LongestSubstringWithoutRepeatingCharactersTest, AllUniqueCharacters) {
    Solution sol;
    std::string s = "abcdefg";
    EXPECT_EQ(sol.lengthOfLongestSubstring(s), 7);
}