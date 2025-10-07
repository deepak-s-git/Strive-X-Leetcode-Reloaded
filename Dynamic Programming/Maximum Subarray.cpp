/*
💡 Problem: Maximum Subarray (LeetCode 53)

Given an integer array `nums`, find the **contiguous subarray** (containing at least one number)
which has the **largest sum**, and return that sum.

📥 Example:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6

Explanation:
The subarray [4, -1, 2, 1] has the largest sum = 6.

⚙️ Constraints:
- 1 <= nums.length <= 10^5
- -10^4 <= nums[i] <= 10^4
*/


/* ================================================================
   ✅ Approach : Dynamic Programming (Kadane's Algorithm)
   ================================================================
   🔍 Intuition:
   - At every index `i`, the maximum subarray ending at `i` is:
        dp[i] = nums[i] + max(dp[i - 1], 0)
   - This means:
       - If the previous subarray sum `dp[i-1]` is positive, extend it.
       - If it's negative, start a new subarray from `nums[i]`.

   - Keep track of the global maximum while building the `dp` array.

   📊 Dry Run:
   nums = [-2,1,-3,4,-1,2,1,-5,4]

   dp[0] = -2         → maxSum = -2
   dp[1] = 1          → maxSum = 1
   dp[2] = -2         → maxSum = 1
   dp[3] = 4          → maxSum = 4
   dp[4] = 3          → maxSum = 4
   dp[5] = 5          → maxSum = 5
   dp[6] = 6          → maxSum = 6
   dp[7] = 1          → maxSum = 6
   dp[8] = 5          → maxSum = 6

   ✅ Final Answer = 6

   ⏱️ Complexity:
   - Time:  O(n)   (single pass)
   - Space: O(n)   (can be optimized to O(1), see Approach 2)
================================================================ */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];

        int maxSum = nums[0];

        for (int i = 1; i < n; i++) {
            dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            maxSum = max(maxSum, dp[i]);
        }

        return maxSum;
    }
};