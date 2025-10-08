/*
💰 Problem: Coin Change (LeetCode 322)

You are given an integer array `coins` representing coin denominations 
and an integer `amount` representing a total amount of money.

Return the **fewest number of coins** needed to make up that amount.
If it is not possible, return -1.

📥 Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

📥 Example 2:
Input: coins = [2], amount = 3
Output: -1

📥 Example 3:
Input: coins = [1], amount = 0
Output: 0

⚙️ Constraints:
- 1 <= coins.length <= 12
- 1 <= coins[i] <= 2^31 - 1
- 0 <= amount <= 10^4
*/


/* ================================================================
   ✅ Approach : Bottom-Up Dynamic Programming (Tabulation)
   ================================================================
   🔍 Intuition:
   - We build a DP array `dp[amt]` where `dp[amt]` = minimum number of coins 
     needed to make up amount `amt`.
   - Initialize `dp[0] = 0` (0 coins to make amount 0).
   - For each amount from 1 to total, try every coin and take the minimum.

   🧠 Transition Formula:
   dp[amt] = min(dp[amt], dp[amt - coin] + 1)   if (coin <= amt)

   📊 Dry Run:
   coins = [1, 2, 5], total = 11

   dp initially: [0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF]
   - amt = 1: coin=1 -> dp[1] = dp[0] + 1 = 1
   - amt = 2: coin=1 -> dp[2] = dp[1] + 1 = 2
              coin=2 -> dp[2] = dp[0] + 1 = 1 ✅
   - ...
   - amt = 11: dp[11] = min(dp[6]+1 (5), dp[9]+1 (5), dp[10]+1 (4)) = 3 ✅

   ⏱️ Complexity:
   - Time:  O(n * amount)  where n = number of coins
   - Space: O(amount)      for the DP array
================================================================ */

class Solution {
public:
    int coinChange(vector<int>& coins, int total) {
        int n = total + 1;                   // Use total+1 as an "infinity" value
        vector<int> dp(n, n);                // Initialize all with INF
        dp[0] = 0;                           // Base case: 0 coins for amount 0

        for (int amt = 1; amt <= total; ++amt) {
            for (int coin : coins) {
                if (coin <= amt) {
                    dp[amt] = min(dp[amt], dp[amt - coin] + 1);
                }
            }
        }

        return dp[total] == n ? -1 : dp[total];
    }
};

