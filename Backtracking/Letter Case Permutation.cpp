/*
Problem: Letter Case Permutation (LeetCode #784)
-----------------------------------------------
Given a string `s`, return a list of all possible strings we can create by toggling 
each letter's case independently. Digits remain unchanged.

Example:
--------
Input:  s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Constraints:
------------
- 1 <= s.length <= 12
- s consists of letters and digits.
*/


// -----------------------------------------------------------------------------
// ✅ Approach: DFS + Backtracking
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// We recursively explore two choices for every character:
//   1. Keep it as is.
//   2. Toggle its case (if it's a letter).
// Digits are always kept unchanged since they have no case.
//
// ⚡ Why This Works:
// Backtracking ensures we explore every combination of uppercase/lowercase choices.
// At each recursion step, we branch into all valid possibilities and build the result.
//
// ⏱️ Time Complexity: O(2^L)
//      - L = number of letters (each can be upper/lower)
// 📦 Space Complexity: O(L) recursion depth (stack) + O(2^L) for result
// -----------------------------------------------------------------------------


class Solution {
public:
    vector<string> letterCasePermutation(string str) {
        vector<string> result;
        dfs(str, 0, result); // Start DFS from index 0
        return result;
    }
    
private:
    // DFS helper function to explore all case permutations
    void dfs(string &s, int idx, vector<string> &res) {
        // ✅ Base case: reached end of string → store the permutation
        if (idx == s.size()) {
            res.push_back(s);
            return;
        }

        char ch = s[idx];

        // 🔁 Option 1: Toggle case (if it's a letter)
        if (isalpha(ch)) {
            s[idx] = islower(ch) ? toupper(ch) : tolower(ch);  // flip case
            dfs(s, idx + 1, res);                              // explore this branch
            s[idx] = ch;                                       // 🔁 backtrack
        }

        // 🔁 Option 2: Keep original character
        dfs(s, idx + 1, res);
    }
};
