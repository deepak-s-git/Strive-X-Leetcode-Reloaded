/*
🏠 Problem: House Robber (LeetCode 198)

You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, but:
- Adjacent houses have security systems connected.
- Robbing two adjacent houses on the same night triggers the alarm.

Return the **maximum amount of money** you can rob **without alerting the police**.

📥 Example:
Input: houses = [2,7,9,3,1]
Output: 12

Explanation:
Rob house 1 (2) + house 3 (9) + house 5 (1) = 12  
You cannot rob house 2 (7) and house 3 (9) together because they are adjacent.

⚙️ Constraints:
- 1 <= houses.length <= 100
- 0 <= houses[i] <= 400
*/


/* ================================================================
   ✅ Approach: Dynamic Programming (Bottom-Up)
   ================================================================
   🔍 Intuition:
   - At each house `i`, you have two choices:
     1. **Skip it**: Take the best solution up to `i-1`.
     2. **Rob it**: Add current money `houses[i]` + best solution up to `i-2`.

   - So, recurrence:
        dp[i] = max(dp[i - 1], houses[i] + dp[i - 2])

   - The answer is `dp[n-1]` (best solution for all houses).

   🧠 Steps:
   1. Handle base cases:
      - If only one house → rob it.
      - If two houses → rob the richer one.
   2. Build the `dp` table iteratively using the above recurrence.
   3. Return the last state.

   📊 Example Dry Run:
   houses = [2,7,9,3,1]

   dp[0] = 2
   dp[1] = max(2, 7) = 7
   dp[2] = max(7, 2+9) = 11
   dp[3] = max(11, 7+3) = 11
   dp[4] = max(11, 11+1) = 12

   ✅ Answer = 12

   ⏱️ Complexity:
   - Time:  O(n)   (one pass through the houses)
   - Space: O(n)   (can be reduced to O(1) using two variables)
================================================================ */

class Solution {
public:
    int rob(vector<int>& houses) {
        int n = houses.size();
        if (n == 1) return houses[0];

        // DP table where dp[i] = max money till house i
        vector<int> dp(n, 0);
        dp[0] = houses[0];
        dp[1] = max(houses[0], houses[1]);

        // Fill DP table
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], houses[i] + dp[i - 2]);
        }

        return dp[n - 1];
    }
};
