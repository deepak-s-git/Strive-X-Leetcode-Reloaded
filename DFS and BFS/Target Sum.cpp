/*
Problem: Target Sum (LeetCode #494)
-----------------------------------
You are given an integer array `nums` and an integer `target`. 
You want to build expressions by adding either `+` or `-` before each number 
and evaluate the expression.

Return the number of different expressions that evaluate to `target`.

Example:
--------
Input: nums = [1,1,1,1,1], target = 3
Output: 5

Constraints:
------------
- 1 <= nums.length <= 20
- 0 <= nums[i] <= 1000
- 0 <= sum(nums[i]) <= 1000
- -1000 <= target <= 1000
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Subset Sum Transformation + DP
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Let totalSum = sum(nums).
// - Assign `+` to some elements and `-` to others. We need:
//       P - N = target   (P = sum of positive, N = sum of negative)
//   =>  P = (target + totalSum) / 2
// - Thus, problem reduces to counting subsets of nums with sum = subsetTarget.
// - This is a classic **subset sum count** DP problem.
//
// ⏱️ Time Complexity: O(n * subsetTarget)
// 📦 Space Complexity: O(subsetTarget)
// -----------------------------------------------------------------------------
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // ❌ If target is not achievable
        if (abs(target) > totalSum || (target + totalSum) % 2 != 0) 
            return 0;

        int subsetTarget = (target + totalSum) / 2;
        return countSubsets(nums, subsetTarget);
    }

private:
    // 🔁 Count number of subsets with given sum using DP
    int countSubsets(vector<int>& nums, int subsetTarget) {
        vector<int> dp(subsetTarget + 1, 0);
        dp[0] = 1;  // one way to make sum 0 (empty subset)

        for (int num : nums) {
            for (int s = subsetTarget; s >= num; --s) {
                dp[s] += dp[s - num];
            }
        }
        return dp[subsetTarget];
    }
};
