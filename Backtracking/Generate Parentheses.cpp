/*
Problem: Generate Parentheses (LeetCode #22)
--------------------------------------------
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example:
--------
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Constraints:
------------
- 1 <= n <= 8
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Backtracking / DFS
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Build the string step by step using recursion.
// - At each step, we can add '(' if we still have some left to use.
// - We can add ')' only if it doesn’t exceed the number of '(' used so far.
// - Once the current string length is `2 * n`, it’s a valid combination.
// - Backtrack to explore all possibilities.
//
// ⏱️ Time Complexity: O(2^(2n)) ≈ O(4^n / √n)
// 📦 Space Complexity: O(2n) recursion depth + output storage
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(0, 0, "", n, result);
        return result;
    }

private:
    // 🔁 Backtracking function
    void backtrack(int open, int close, string current, int n, vector<string>& result) {
        // ✅ Base case: formed a valid parentheses string
        if (current.size() == n * 2) {
            result.push_back(current);
            return;
        }

        // ✋ Option 1: Add '(' if we still have any left
        if (open < n) {
            backtrack(open + 1, close, current + "(", n, result);
        }

        // ✋ Option 2: Add ')' if it keeps the string valid
        if (close < open) {
            backtrack(open, close + 1, current + ")", n, result);
        }
    }
};
