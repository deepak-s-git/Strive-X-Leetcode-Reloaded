/*
💠 Problem: Partition to K Equal Sum Subsets (LeetCode 698)

You are given an integer array `nums` and an integer `k`.
Return true if it is possible to divide this array into `k` non-empty subsets whose sums are all equal.

📥 Example 1:
Input: nums = [4,3,2,3,5,2,1], k = 4  
Output: true  
Explanation: It's possible to divide into 4 subsets (5), (1,4), (2,3), (2,3).

📥 Example 2:
Input: nums = [1,2,3,4], k = 3  
Output: false

⚙️ Constraints:
- 1 <= k <= nums.length <= 16
- 0 < nums[i] < 10000
- The sum of all elements in `nums` is divisible by `k`
*/


/* ================================================================
   ✅ Approach 1: Bitmask + Memoization (DFS)
   ================================================================
   🔍 Intuition:
   - Each element can belong to one of the `k` subsets.
   - The total sum must be divisible by `k`, and each subset should sum to `target = totalSum / k`.
   - We use bitmasking to represent which elements are used.
   - Recursively try to fill subsets until all are formed.

   🧠 Core Idea:
   - `usedMask`: bitmask representing used elements.
   - `remainingSum`: how much space is left in the current subset.
   - `remainingSubsets`: how many subsets still need to be formed.
   - Memoization is done based on `usedMask` to avoid recomputation.

   ⏱️ Complexity:
   - Time:  O(n * 2^n)     (each subset configuration is computed once)
   - Space: O(2^n)         (for memoization table)
================================================================ */

class Solution {
public:
    int subsetTarget;

    bool canForm(vector<int>& nums, int usedMask, int remainingSum, int remainingSubsets, vector<int>& memo) {
        // ✅ Base case: all subsets formed
        if (remainingSubsets == 0) return true;

        // ✅ If this state already computed, return cached result
        if (memo[usedMask] != -1) return memo[usedMask];

        for (int i = 0; i < nums.size(); i++) {
            // Skip if already used or element too large
            if (usedMask & (1 << i) || nums[i] > remainingSum) continue;

            int newMask = usedMask | (1 << i);

            // Case 1: this element completes the current subset
            if (nums[i] == remainingSum && canForm(nums, newMask, subsetTarget, remainingSubsets - 1, memo))
                return memo[usedMask] = 1;

            // Case 2: continue building current subset
            else if (canForm(nums, newMask, remainingSum - nums[i], remainingSubsets, memo))
                return memo[usedMask] = 1;
        }

        return memo[usedMask] = 0;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % k != 0) return false;  // Can't partition equally

        subsetTarget = totalSum / k;
        vector<int> memo(1 << nums.size(), -1);

        return canForm(nums, 0, subsetTarget, k, memo);
    }
};
