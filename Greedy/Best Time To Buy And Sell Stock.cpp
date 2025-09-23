/*
Problem: Best Time to Buy and Sell Stock (LeetCode 121)
--------------------------------------------------------
You are given an array prices where prices[i] is the price of a given 
stock on the i-th day. You want to maximize your profit by choosing a 
single day to buy one stock and choosing a different day in the future 
to sell that stock.

Return the maximum profit you can achieve. If you cannot achieve any profit, return 0.

Examples:
---------
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: No profitable transaction possible.

Constraints:
------------
- 1 <= prices.length <= 10^5
- 0 <= prices[i] <= 10^4
*/


// -----------------------------------------------------------------------------
// Approach 1: Brute Force (Check All Buy/Sell Pairs)
// -----------------------------------------------------------------------------
// For each day i, check every future day j and compute profit = prices[j] - prices[i].
// Keep track of the maximum profit found.
//
// Time Complexity: O(n^2)   -> TLE for large inputs
// Space Complexity: O(1)
//
class Solution_BruteForce {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                maxProfit = max(maxProfit, prices[j] - prices[i]);
            }
        }
        return maxProfit;
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Optimized Single Pass with Tracking Minimum Price
// -----------------------------------------------------------------------------
// Idea:
// - Track the minimum price so far (best day to buy).
// - For each day, compute potential profit = prices[i] - bestBuy.
// - Update maxProfit accordingly.
// - Always update bestBuy to the lowest price seen so far.
// - One pass through the array is enough.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int bestBuy = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > bestBuy) {
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }
            bestBuy = min(bestBuy, prices[i]);
        }
        return maxProfit;
    }
};
