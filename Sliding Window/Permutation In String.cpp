/*
Problem: Permutation in String (LeetCode #567)
-----------------------------------------------
Given two strings s1 and s2, return true if s2 contains a permutation of s1,
or false otherwise.

In other words, return true if one of s1's permutations is a substring of s2.

Examples:
---------
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains "ba", which is a permutation of "ab".

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Constraints:
------------
- 1 <= s1.length, s2.length <= 10^4
- s1 and s2 consist of lowercase English letters.
*/

// -----------------------------------------------------------------------------
// Approach: Sliding Window + HashMap
// -----------------------------------------------------------------------------
// Idea:
// - Use two hashmaps (frequency counts) for s1 and a sliding window in s2.
// - Initialize the window with the first s1.length() characters of s2.
// - Then slide the window one character at a time:
//      - Add the new character (right side).
//      - Remove the old character (left side).
// - If at any point the two hashmaps match, return true.
// - Otherwise, after scanning all windows, return false.
//
// Time Complexity: O(n)  -> where n = length of s2
// Space Complexity: O(1) -> at most 26 characters in the hash maps
//
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        unordered_map<char, int> str1;
        unordered_map<char, int> str2;

        // Count frequency of characters in s1 and the first window of s2
        for (int i = 0; i < s1.length(); i++) {
            str1[s1[i]]++;
            str2[s2[i]]++;
        }

        if (str1 == str2) {
            return true;
        }

        int left = 0;
        for (int right = s1.length(); right < s2.length(); right++) {
            // Add new character to the window
            str2[s2[right]]++;
            // Remove old character from the window
            str2[s2[left]]--;
            if (str2[s2[left]] == 0) {
                str2.erase(s2[left]);
            }
            left++;

            if (str1 == str2) {
                return true;
            }
        }

        return false;
    }
};
