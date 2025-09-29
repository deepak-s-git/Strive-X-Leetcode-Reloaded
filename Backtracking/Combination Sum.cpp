/*
Problem: Combination Sum (LeetCode #39)
---------------------------------------
Given an array of distinct integers `candidates` and a target integer `target`,
return all unique combinations of `candidates` where the chosen numbers sum to `target`.
You may use the same number from `candidates` an unlimited number of times.

Example:
--------
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

Constraints:
------------
- 1 <= candidates.length <= 30
- 1 <= candidates[i] <= 200
- All elements of candidates are distinct.
- 1 <= target <= 500
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Backtracking / DFS
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Explore all combinations using recursion.
// - At each step, decide to either:
//     1️⃣ Include the current candidate (stay at same idx since unlimited use allowed)
//     2️⃣ Skip the current candidate (move to idx+1)
// - If the running sum equals `target`, add the current combination to results.
// - Backtrack after exploring each choice.
//
// ⏱️ Time Complexity: Exponential in worst case
// 📦 Space Complexity: O(target / min(candidates)) recursion depth + output storage
// -----------------------------------------------------------------------------
#include <vector>
using namespace std;

class Solution {
public:
    // 🔁 Recursive helper
    void solve(vector<int>& candidates, int idx, int target,
               vector<int>& current, vector<vector<int>>& ans) {
        // ✅ Base case: exact target achieved
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        // ❌ Out of bounds or target overshot
        if (idx >= candidates.size() || target < 0)
            return;

        // Include current candidate
        current.push_back(candidates[idx]);
        solve(candidates, idx, target - candidates[idx], current, ans);
        current.pop_back(); // backtrack

        // Exclude current candidate and move to next
        solve(candidates, idx + 1, target, current, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;

        solve(candidates, 0, target, current, ans);
        return ans;
    }
};
