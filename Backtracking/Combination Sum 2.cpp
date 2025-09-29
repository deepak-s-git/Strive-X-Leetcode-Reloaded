/*
Problem: Combination Sum II (LeetCode #40)
------------------------------------------
Given a collection of candidate numbers (candidates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used **once** in the combination.

Examples:
---------
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: [
  [1,1,6],
  [1,2,5],
  [1,7],
  [2,6]
]

Constraints:
------------
- 1 <= candidates.length <= 100
- 1 <= candidates[i] <= 50
- 1 <= target <= 30
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Backtracking + DFS + Sorting
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Sort the array to easily skip duplicates and prune branches.
// - Explore each number starting from `start` index.
// - Include the number and recurse with reduced target and next index (i+1).
// - Backtrack after exploring each choice.
// - Skip duplicate numbers at the same recursion level to avoid duplicate combinations.
//
// ⏱️ Time Complexity: O(2^n * k) worst case, n = number of candidates, k = average combination length
// 📦 Space Complexity: O(k) recursion depth + output storage
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());             // sort to handle duplicates and allow pruning
        vector<vector<int>> result;                 // store all unique combinations
        vector<int> comb;                           // current combination
        dfs(nums, target, 0, comb, result);        // start backtracking
        return result;
    }

private:
    void dfs(vector<int>& nums, int target, int start, vector<int>& comb, vector<vector<int>>& result) {
        if (target == 0) {                          // ✅ Base case: target reached
            result.push_back(comb);
            return;
        }

        if (target < 0 || start >= nums.size()) return;  // ❌ Prune: target negative or index out of bounds

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;  // 🔁 Skip duplicates at same recursion level
            if (nums[i] > target) break;                         // 🔁 Prune: number exceeds remaining target

            comb.push_back(nums[i]);                             // include current number
            dfs(nums, target - nums[i], i + 1, comb, result);   // recurse with next index
            comb.pop_back();                                     // backtrack to explore other possibilities
        }
    }
};
