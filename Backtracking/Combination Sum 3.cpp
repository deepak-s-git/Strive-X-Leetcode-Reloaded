/*
Problem: Combination Sum III (LeetCode #216)
--------------------------------------------
Find all possible combinations of `k` numbers that add up to a number `n`, using numbers 1 to 9.
Each number can be used at most once in a combination.

Example:
--------
Input: k = 3, n = 7
Output: [[1,2,4]]

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]

Constraints:
------------
- 2 <= k <= 9
- 1 <= n <= 60
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Backtracking / DFS
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Build combinations incrementally using recursion.
// - At each step, pick a number from `start` to 9.
// - Include the number in current combination, decrease remaining `k` and `target` accordingly.
// - If `k == 0` and `target == 0`, a valid combination is found → add to result.
// - Backtrack to explore other possibilities.
// - Stop early if current number exceeds remaining target or k becomes zero.
//
// ⏱️ Time Complexity: O(C(9,k) * k)
// 📦 Space Complexity: O(k) recursion depth + output storage
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> result;  // stores all valid combinations

    // Helper DFS function to build combinations
    void dfs(int k, int target, int start, vector<int>& comb) {
        // ✅ Base case: combination of size k sums to target
        if (target == 0 && k == 0) {
            result.push_back(comb);
            return;
        }

        // 🔁 Try numbers from start to 9
        for (int num = start; num <= 9; ++num) {
            // ❌ Prune: if num exceeds remaining target or no slots left
            if (num > target || k <= 0) break;

           
