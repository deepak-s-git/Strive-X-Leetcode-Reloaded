/*
Problem: Minimum Window Substring (LeetCode #76)
------------------------------------------------
Given two strings s and t of lengths m and n, return the minimum window substring 
of s such that every character in t (including duplicates) is included in the window. 
If no such substring exists, return "".

Examples:
---------
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"

Input: s = "a", t = "a"
Output: "a"

Input: s = "a", t = "aa"
Output: ""

Constraints:
------------
- 1 <= s.length, t.length <= 10^5
- s and t consist of uppercase and lowercase English letters.
*/


// -----------------------------------------------------------------------------
// Approach: Sliding Window + Frequency Count
// -----------------------------------------------------------------------------
// Idea:
// - Count frequency of all characters in `t`.
// - Expand the window using `right` and decrease freq when a required char is used.
// - Track `required`, the number of characters still needed to satisfy `t`.
// - When `required == 0`, try to shrink from left to minimize the window.
// - Update best window whenever a smaller valid window is found.
//
// Time Complexity: O(m + n)  (each char visited at most twice)
// Space Complexity: O(1)     (fixed size freq array for ASCII chars)
//
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) {
            return "";
        }

        vector<int> freq(128, 0);      // ASCII frequency map
        for (char ch : t) {
            freq[ch]++;
        }

        int required = t.size();       // characters still needed
        int left = 0, right = 0;       // sliding window pointers
        int minLength = INT_MAX;       // length of best window
        int bestStart = 0;             // start index of best window

        while (right < s.size()) {
            // Expand window
            if (freq[s[right++]]-- > 0) {
                required--;
            }

            // Shrink window when valid
            while (required == 0) {
                if (right - left < minLength) {
                    minLength = right - left;
                    bestStart = left;
                }

                if (freq[s[left++]]++ == 0) {
                    required++;
                }
            }
        }

        return (minLength == INT_MAX) ? "" : s.substr(bestStart, minLength);
    }
};
