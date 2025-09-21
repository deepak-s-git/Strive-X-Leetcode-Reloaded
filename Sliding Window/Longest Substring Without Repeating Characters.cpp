/*
Problem: Longest Substring Without Repeating Characters (LeetCode #3)
----------------------------------------------------------------------
Given a string s, find the length of the longest substring without 
repeating characters.

Examples:
---------
Input: s = "abcabcbb"
Output: 3
Explanation: "abc" is the answer.

Input: s = "bbbbb"
Output: 1

Input: s = "pwwkew"
Output: 3

Constraints:
------------
- 0 <= s.length <= 5 * 10^4
- s consists of English letters, digits, symbols, and spaces.
*/


// -----------------------------------------------------------------------------
// Approach 1: Sliding Window + HashSet
// -----------------------------------------------------------------------------
// Idea:
// - Maintain a window [left, right].
// - Use a hash set to ensure uniqueness in the window.
// - If a duplicate is found, shrink from left until no duplicate remains.
// - Expand right and update max length.
//
// Time Complexity: O(n^2) in worst case (because each erase can cause multiple moves)
// Space Complexity: O(n)
//
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLen = 0;
        unordered_set<char> charS;

        for (int right = 0; right < s.length(); right++) {
            while (charS.find(s[right]) != charS.end()) {
                charS.erase(s[left]);
                left++;
            }
            charS.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;        
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Sliding Window + Frequency Map
// -----------------------------------------------------------------------------
// Idea:
// - Use a hash map to store frequency of chars in the window.
// - Expand window by moving right pointer.
// - If a duplicate (freq > 1) occurs, shrink window from left until valid.
// - Keep track of max window length.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
//
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int left = 0;
        unordered_map<char, int> count;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            count[c]++;

            while (count[c] > 1) {
                char leftChar = s[left];
                count[leftChar]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};


// -----------------------------------------------------------------------------
// Approach 3: Sliding Window + Last Seen Index (Optimal)
// -----------------------------------------------------------------------------
// Idea:
// - Use a hash map to store the last seen index of each character.
// - If the current character was seen inside the current window,
//   move `left` to `lastSeen[c] + 1`.
// - Update maxLen each iteration.
//
// Time Complexity: O(n) (each index visited once)
// Space Complexity: O(n)
//
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int left = 0;
        unordered_map<char, int> lastSeen;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            if (lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= left) {
                left = lastSeen[c] + 1;
            }
            maxLen = max(maxLen, right - left + 1);
            lastSeen[c] = right;
        }
        return maxLen;
    }
};
