// 002_longest_substring_no_repeating solution.cpp
// Given a string s, find the length of the longest without duplicate characters.
// Example 1:
//
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
//
// Example 2:
//
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
// Example 3:
//
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
// Constraints:
//     0 <= s.length <= 5 * 104
//     s consists of English letters, digits, symbols and spaces.


#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        
        std::vector<char> char_vector;

        for(char c: s) {
            auto it = std::find(char_vector.begin(), char_vector.end(), c);
            if(it == char_vector.end()) {
                    char_vector.push_back(c);
            } else {
                char_vector.clear();
            }
        }

        return char_vector.size();
    }
};
