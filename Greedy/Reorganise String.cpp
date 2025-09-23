/*
Problem: Reorganize String (LeetCode #767)
------------------------------------------
Given a string `s`, rearrange the characters of `s` so that no two adjacent
characters are the same. If it is not possible, return an empty string.

Examples:
---------
Input: s = "aab"
Output: "aba"

Input: s = "aaab"
Output: ""

Constraints:
------------
- 1 <= s.length <= 500
- s consists of lowercase English letters.
*/


// -----------------------------------------------------------------------------
// Approach: Greedy + Even/Odd Index Placement
// -----------------------------------------------------------------------------
// Idea:
// 1. Count the frequency of each character.
// 2. If the most frequent character appears more than (n+1)/2 times, 
//    rearrangement is impossible → return "".
// 3. Place the most frequent character at even indices (0, 2, 4, ...).
// 4. Fill the remaining characters in the leftover positions (first even slots,
//    then odd slots).
//
// Why this works:
// - Placing the most frequent character in spaced-out even positions ensures 
//   that they do not end up adjacent.
// - The remaining characters can always fit into the gaps.
//
// Time Complexity: O(n + 26) ≈ O(n)
// Space Complexity: O(26) ≈ O(1)
// -----------------------------------------------------------------------------
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        int freq[26] = {0};      // frequency count of each character
        int mostFreqChar = 0;    // index of most frequent character
        int highestFreq = 0;     // frequency of the most frequent character

        // Step 1: Count frequencies and find the most frequent character
        for (char c : s) {
            int idx = c - 'a';
            freq[idx]++;
            if (freq[idx] > highestFreq) {
                highestFreq = freq[idx];
                mostFreqChar = idx;
            }
        }

        // Step 2: If impossible, return ""
        if (highestFreq > (n + 1) / 2) return "";

        int pos = 0; // position pointer

        // Step 3: Place the most frequent character first at even indices
        while (freq[mostFreqChar] > 0) {
            s[pos] = 'a' + mostFreqChar;
            pos += 2;
            freq[mostFreqChar]--;
        }

        // Step 4: Place remaining characters
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                // if even slots are filled, move to odd slots
                if (pos >= n) pos = 1;
                s[pos] = 'a' + i;
                pos += 2;
                freq[i]--;
            }
        }

        return s;
    }
};
