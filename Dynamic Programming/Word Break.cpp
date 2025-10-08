/*
📚 Problem: Word Break (LeetCode 139)

Given a string `s` and a dictionary of strings `wordDict`, return `true` 
if `s` can be segmented into a space-separated sequence of one or more dictionary words.

📥 Example 1:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: "leetcode" = "leet" + "code"

📥 Example 2:
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: "applepenapple" = "apple" + "pen" + "apple"

📥 Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false

⚙️ Constraints:
- 1 <= s.length <= 300
- 1 <= wordDict.length <= 1000
- 1 <= word.length <= 20
- `s` and `wordDict[i]` consist only of lowercase English letters.
*/

/* ================================================================
   ✅ Approach 1: Dynamic Programming (Bottom-Up)
   ================================================================
   🔍 Intuition:
   - We want to know if `s[0..i]` can be formed by dictionary words.
   - Define `canBreak[i]` = true if `s[0..i-1]` can be segmented.
   - Initially, `canBreak[0] = true` (empty string is always valid).
   - For each position `end` in the string:
       - Check every word in `wordDict`.
       - If the word matches the substring ending at `end`
         **and** `canBreak[start]` is true (where `start = end - word.length()`),
         then `canBreak[end] = true`.

   📊 Dry Run:
   s = "leetcode", wordDict = ["leet","code"]

   canBreak: [T, F, F, F, F, F, F, F, F]
   - end=4: "leet" ✅ canBreak[4] = true
   - end=8: "code" ✅ canBreak[8] = true

   Answer: canBreak[8] = true ✅

   ⏱️ Complexity:
   - Time:  O(n * m * L)  
       where n = length of s, m = number of words, L = max word length  
   - Space: O(n)         (for DP array)
================================================================ */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> canBreak(n + 1, false); 
        canBreak[0] = true;  // Base case: empty string

        for (int end = 1; end <= n; end++) {
            for (const string& word : wordDict) {
                int start = end - word.size();
                // Check if word fits and substring matches
                if (start >= 0 && canBreak[start] && s.substr(start, word.size()) == word) {
                    canBreak[end] = true;
                    break;  // No need to check other words
                }
            }
        }

        return canBreak[n]; 
    }
};
