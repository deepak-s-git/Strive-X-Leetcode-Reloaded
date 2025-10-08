/*
💥 Problem: Maximum Product Subarray (LeetCode 152)

Given an integer array `nums`, find the contiguous subarray 
(containing at least one number) which has the **largest product**, 
and return its product.

📥 Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: The subarray [2,3] has the largest product = 6.

📥 Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a contiguous subarray.

⚙️ Constraints:
- 1 <= nums.length <= 2 * 10^4
- -10 <= nums[i] <= 10
- The product of any prefix or suffix of `nums` is guaranteed to fit in a 32-bit integer.
*/

/* ================================================================
   ✅ Approach 1: Dynamic Programming (Track Min & Max Products)
   ================================================================
   🔍 Intuition:
   - The tricky part is negative numbers. Multiplying by a negative 
     flips the sign, so the maximum can become minimum and vice versa.
   - We keep track of:
       - `currentMax`: Maximum product ending at current index
       - `currentMin`: Minimum product ending at current index
   - If the current number is negative, swap them before updating.
   - Update the result with the global maximum at each step.

   📊 Dry Run:
   nums = [2, 3, -2, 4]

   i=0: val=2  -> currentMax=2, currentMin=2, overallMax=2
   i=1: val=3  -> currentMax=6, currentMin=3, overallMax=6
   i=2: val=-2 -> swap → currentMax=-2, currentMin=-12, overallMax=6
   i=3: val=4  -> currentMax=4, currentMin=-48, overallMax=6

   ✅ Final Answer = 6

   ⏱️ Complexity:
   - Time:  O(n)   -> Single pass through the array
   - Space: O(1)   -> Only constant extra space used
================================================================ */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentMax = 1;           // Maximum product ending at current position
        int currentMin = 1;           // Minimum product ending at current position
        int overallMax = INT_MIN;     // Global maximum product seen so far

        for (int value : nums) {
            if (value < 0) {
                swap(currentMax, currentMin);  // Swap if negative flips sign
            }

            // Either start fresh from current value or extend previous product
            currentMax = max(value, currentMax * value);
            currentMin = min(value, currentMin * value);

            overallMax = max(overallMax, currentMax);
        }

        return overallMax;
    }
};
