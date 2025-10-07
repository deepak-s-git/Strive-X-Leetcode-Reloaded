/*
💡 Problem: House Robber II (LeetCode 213)

You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed. All houses are arranged in a **circle**.
That means the **first house is the neighbor of the last one**, so you cannot rob both.

Return the **maximum amount of money** you can rob **without robbing two adjacent houses**.

📥 Example:
Input: houses = [2,3,2]
Output: 3
Explanation: Rob house 2 (money = 3) and skip the first and last.

📥 Example 2:
Input: houses = [1,2,3,1]
Output: 4
Explanation: Rob houses 1 and 3.

⚙️ Constraints:
- 1 <= houses.length <= 100
- 0 <= houses[i] <= 1000
*/


/* ================================================================
   ✅ Approach 1: Dynamic Programming + Circular Constraint
   ================================================================
   🔍 Intuition:
   - In the original House Robber problem (linear street), we use DP:
       dp[i] = max(dp[i-1], dp[i-2] + houses[i])
   - But here houses are in a **circle**, so first and last cannot both be robbed.
   - Solution: Break into two linear subproblems:
       1️⃣ Rob houses from index 0 to n-2 (exclude last)
       2️⃣ Rob houses from index 1 to n-1 (exclude first)
   - The final answer is max of these two results.

   📊 Dry Run:
   houses = [2,3,2]
   - Case 1: Rob [2,3] → max = 3
   - Case 2: Rob [3,2] → max = 3
   ✅ Answer = max(3, 3) = 3

   ⏱️ Complexity:
   - Time:  O(n)   (we solve 2 linear DP problems)
   - Space: O(1)   (optimized DP without extra array)
================================================================ */

class Solution {
public:
    int rob(vector<int>& houses) {
        int n = houses.size();

        // If there's only one house, rob it.
        if (n == 1) return houses[0];

        // Compare two scenarios: exclude first OR exclude last
        return max(robLinear(houses, 0, n - 2), robLinear(houses, 1, n - 1));
    }

private:
    // Helper function for standard House Robber I (linear DP)
    int robLinear(vector<int>& houses, int start, int end) {
        int prev = 0, curr = 0;

        for (int i = start; i <= end; ++i) {
            int temp = max(curr, prev + houses[i]); // choose robbing current or skipping
            prev = curr;
            curr = temp;
        }

        return curr;
    }
};