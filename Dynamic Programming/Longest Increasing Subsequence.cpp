/*
📈 Problem: Longest Increasing Subsequence (LeetCode 300)

Given an integer array `nums`, return the length of the **longest strictly increasing subsequence**.

A subsequence is a sequence derived from the array by deleting some or no elements 
without changing the order of the remaining elements.

📥 Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], so length = 4.

📥 Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

📥 Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1

⚙️ Constraints:
- 1 <= nums.length <= 2500
- -10^4 <= nums[i] <= 10^4
*/

/* ================================================================
   ✅ Approach 1: Dynamic Programming (O(n^2))
   ================================================================
   🔍 Intuition:
   - Define `lisLength[i]` as the length of the longest increasing subsequence 
     that ends at index `i`.
   - For each `i`, check all previous elements `j < i`:
       - If `nums[i] > nums[j]`, we can extend the subsequence ending at `j`.
       - Update: `lisLength[i] = max(lisLength[i], lisLength[j] + 1)`
   - The final answer is the maximum value in the `lisLength` array.

   📊 Dry Run:
   nums = [10, 9, 2, 5, 3, 7, 101, 18]

   lisLength = [1, 1, 1, 2, 2, 3, 4, 4]
   Result = 4 ✅

   ⏱️ Complexity:
   - Time:  O(n^2)   -> Nested loops
   - Space: O(n)     -> DP array to store LIS lengths
================================================================ */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        vector<int> lisLength(n, 1);  // Each element is LIS of length 1 by itself

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    lisLength[i] = max(lisLength[i], lisLength[j] + 1);
                }
            }
        }

        return *max_element(lisLength.begin(), lisLength.end());
    }
};
