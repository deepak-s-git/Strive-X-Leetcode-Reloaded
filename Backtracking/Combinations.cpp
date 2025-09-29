/*
Problem: Combinations (LeetCode #77)
-------------------------------------
Given two integers n and k, return all possible combinations of k numbers
chosen from the range [1, n].

Example:
--------
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]

Constraints:
------------
- 1 <= n <= 20
- 1 <= k <= n
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Backtracking / DFS
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Build combinations incrementally using recursion.
// - At each step, choose a number from `start` to `n`.
// - Add number to current combination and recurse with `start = num+1`.
// - Once combination size equals k, add to result.
// - Backtrack to explore other possibilities.
//
// ⏱️ Time Complexity: O(C(n,k) * k)
// 📦 Space Complexity: O(k) recursion depth + output storage
// -----------------------------------------------------------------------------


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> comb;
        dfs(1, comb, result, n, k);
        return result;
    }

private:
    void dfs(int start, vector<int>& comb, vector<vector<int>>& result, int n, int k) {
        // ✅ Base case: combination complete
        if (comb.size() == k) {
            result.push_back(comb);
            return;
        }

        // 🔁 Try each number from start to n
        for (int num = start; num <= n; num++) {
            comb.push_back(num);           // include num
            dfs(num + 1, comb, result, n, k); // recurse
            comb.pop_back();               // backtrack
        }
    }    
};
