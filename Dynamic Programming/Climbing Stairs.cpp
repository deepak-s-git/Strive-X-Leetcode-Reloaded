/*
🔎 Problem: Climbing Stairs (LeetCode 70)

You are climbing a staircase. It takes `n` steps to reach the top.
Each time you can either climb **1 or 2 steps**. 
In how many distinct ways can you climb to the top?

📥 Example:
Input: n = 5
Output: 8
Explanation:
There are 8 distinct ways to climb to the top:
1+1+1+1+1  
1+1+1+2  
1+1+2+1  
1+2+1+1  
2+1+1+1  
1+2+2  
2+1+2  
2+2+1

⚙️ Constraints:
- 1 <= n <= 45
*/


/* ================================================================
   ✅ Approach 1: Dynamic Programming (Space Optimized)
   ================================================================
   🔍 Intuition:
   - This is a classic Fibonacci-type problem:
     - Ways to reach step `n` = ways to reach `n-1` + ways to reach `n-2`
     - Because from `n-1` you can jump 1 step, and from `n-2` you can jump 2 steps.
   - Instead of storing all values, we only keep the last two.

   🧠 Steps:
   1. Base cases: 
      - n = 1 → 1 way  
      - n = 2 → 2 ways  
      - n = 3 → 3 ways
   2. For n > 3, use two variables to store results for previous steps.
   3. Update iteratively and return the last computed value.

   ⏱️ Complexity:
   - Time: O(n)   → We compute results from 3 to n
   - Space: O(1)  → Only a few variables are used
================================================================ */

class Solution {
public:
    int climbStairs(int n) {
        // Base cases
        if (n <= 3) return n;

        // prev2: ways to reach (i-2), prev1: ways to reach (i-1)
        int prev2 = 2, prev1 = 3, cur = 0;

        // Compute ways iteratively
        for (int i = 3; i < n; i++) {
            cur = prev1 + prev2;  // recurrence relation
            prev2 = prev1;
            prev1 = cur;
        }

        return cur;
    }
};
