/*
🔎 Problem: Target Sum (LeetCode 494)

You are given an integer array `nums` and an integer `target`.
Your task is to return the number of ways to assign '+' and '-' signs to each element 
in `nums` such that the resulting sum equals `target`.

📥 Example:
Input: nums = [1,1,1,1,1], target = 3
Output: 5

Explanation:
There are 5 ways to assign signs:
-1 +1 +1 +1 +1 = 3
+1 -1 +1 +1 +1 = 3
+1 +1 -1 +1 +1 = 3
+1 +1 +1 -1 +1 = 3
+1 +1 +1 +1 -1 = 3

⚙️ Constraints:
- 1 <= nums.length <= 20
- 0 <= nums[i] <= 1000
- 0 <= target <= 1000
*/


/* ================================================================
   ✅ Approach 1: Subset Sum Transformation (Dynamic Programming)
   ================================================================
   🔍 Intuition:
   - We want: (+subset) - (−subset) = target
   - Let:
       P = sum of elements assigned '+'
       N = sum of elements assigned '-'
     Then:
       P - N = target
       P + N = totalSum
   - Solving both equations:
       2P = totalSum + target
       P = (totalSum + target) / 2

   - This reduces the problem to **counting subsets with sum = P**.

   ⚠️ Edge Cases:
   - If `totalSum + target` is odd → return 0 (not possible)
   - If `abs(target) > totalSum` → return 0 (not possible)

   🧠 Steps:
   1. Calculate `totalSum` of the array.
   2. Transform the problem into counting subsets with sum = `(totalSum + target)/2`.
   3. Use a 2D DP table to count ways:
      - `dp[i][j]` = number of ways to form sum `j` using first `i` elements.
   4. Answer is `dp[n][targetSum]`.

   📊 Example:
   nums = [1,1,1,1,1], target = 3
   totalSum = 5
   P = (5 + 3)/2 = 4
   Count subsets with sum = 4 → 5 ways

   ⏱️ Complexity:
   - Time:  O(n * targetSum)
   - Space: O(n * targetSum)
================================================================ */

class Solution {
public:

    // Helper: Count subsets with a given sum
    int countSubsetsWithSum(vector<int>& nums, int targetSum) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(targetSum + 1, 0));

        // Base Case: There's 1 way to make sum 0 — choose nothing
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        // Build DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= targetSum; j++) {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j]; // include + exclude
                else
                    dp[i][j] = dp[i - 1][j]; // exclude current element
            }
        }
        return dp[n][targetSum];
    }

    // Main function
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        // Invalid case: cannot partition into subsets
        if ((totalSum + target) % 2 != 0 || abs(target) > totalSum)
            return 0;

        // Reduce to subset sum problem
        int targetSum = (totalSum + target) / 2;
        return countSubsetsWithSum(nums, targetSum);
    }
};
