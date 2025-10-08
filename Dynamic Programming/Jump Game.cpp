/*
🏃‍♂️ Problem: Jump Game (LeetCode 55)

You are given an integer array `nums` where each element represents the **maximum jump length** at that position.  
Determine if you can **reach the last index** starting from the first index.

📥 Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step to index 1, then 3 steps to reach the last index.

📥 Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always land at index 3 and cannot move further.

⚙️ Constraints:
- 1 <= nums.length <= 10^4
- 0 <= nums[i] <= 10^5
*/

/* ================================================================
   ✅ Approach 1: Dynamic Programming (Tabulation)
   ================================================================
   🔍 Intuition:
   - Let `dp[i]` = true if we can reach index `i`.
   - Base case: `dp[0] = true` (starting position).
   - For each index `i`, check all previous indices `j < i`.
     - If `dp[j]` is true and `j + nums[j] >= i`, then `dp[i] = true`.

   ⏱️ Complexity:
   - Time:  O(n^2) in worst case
   - Space: O(n) for the DP array
================================================================ */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0); 
        dp[0] = true; // start index

        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && j + nums[j] >= i) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n - 1]; // can we reach last index?
    }
};
