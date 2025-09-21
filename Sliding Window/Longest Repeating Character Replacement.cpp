/*
Problem: Longest Repeating Character Replacement (LeetCode #424)
----------------------------------------------------------------
You are given a string s and an integer k. You can choose any character 
of the string and change it to any other uppercase English character. 
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter 
you can get after performing the above operations.

Examples:
---------
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with 'B's or vice versa.

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the last 'A' with 'B' to form "AABBBB".

Constraints:
------------
- 1 <= s.length <= 10^5
- s consists of only uppercase English letters.
- 0 <= k <= s.length
*/

// -----------------------------------------------------------------------------
// Approach: Sliding Window + Frequency Map
// -----------------------------------------------------------------------------
// Idea:
// - Use a sliding window [left, right] to track the current substring.
// - Maintain a frequency count of characters inside the window.
// - Keep track of the maximum frequency (maxFreq) of any character in the window.
// - If (window length - maxFreq) > k, shrink the window from the left.
//   (means more than k replacements are needed).
// - Otherwise, expand the window and update the result.
//
// Time Complexity: O(n)
// Space Complexity: O(26) ≈ O(1) since only uppercase letters
//
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int res = 0, left = 0, maxFreq = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            maxFreq = max(maxFreq, freq[s[right]]);

            // If we need more than k changes, shrink window
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left]]--;   // decrement LEFT char, not right
                left++;
            }

            res = max(res, right - left + 1);
        }
        return res;
    }
};
