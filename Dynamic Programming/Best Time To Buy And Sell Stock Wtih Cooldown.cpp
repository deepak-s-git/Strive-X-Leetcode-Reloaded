/*
💰 Problem: Best Time to Buy and Sell Stock with Cooldown (LeetCode 309)

You are given an array `prices` where `prices[i]` is the price of a stock on the i-th day.
You may complete as many transactions as you like (buy one and sell one share of the stock multiple times)
with the following restrictions:
- After you sell your stock, you **cannot buy stock on the next day** (i.e., you have a 1-day cooldown).

Return the maximum profit you can achieve.

📥 Example 1:
Input: prices = [1,2,3,0,2]
Output: 3  
Explanation: Transactions = [buy, sell, cooldown, buy, sell]

📥 Example 2:
Input: prices = [1]
Output: 0

⚙️ Constraints:
- 1 <= prices.length <= 5000
- 0 <= prices[i] <= 1000
*/


/* ================================================================
   ✅ Approach 1: Dynamic Programming (State Machine)
   ================================================================
   🔍 Intuition:
   We track three states for each day:
   - `hold`: Maximum profit if we currently hold a stock.
   - `sold`: Maximum profit if we have just sold a stock.
   - `rest`: Maximum profit if we are in a cooldown or have done nothing.

   🔄 Transitions:
   - `hold` → stay holding or buy today → max(prevHold, prevRest - price)
   - `sold` → sell today → prevHold + price
   - `rest` → stay in rest or come from sold → max(prevRest, prevSold)

   💡 Goal:
   - At the end, we cannot hold a stock. So, answer = max(sold, rest).

   ⏱️ Complexity:
   - Time:  O(n)   (single pass)
   - Space: O(1)   (constant variables only)
================================================================ */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int rest = 0;           // No stock, can buy
        int sold = 0;           // Just sold a stock
        int hold = INT_MIN;     // Currently holding a stock

        for (int price : prices) {
            int prevRest = rest;
            int prevSold = sold;
            int prevHold = hold;

            rest = max(prevRest, prevSold);         // Stay idle or cooldown after selling
            sold = prevHold + price;                // Sell the stock today
            hold = max(prevHold, prevRest - price); // Buy today or keep holding
        }

        return max(sold, rest);  // Max profit when not holding stock
    }
};
