/*
💠 Problem: Partition Equal Subset Sum (LeetCode 416)

Given an integer array `nums`, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal.

📥 Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1,5,5] and [11].

📥 Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal-sum subsets.

⚙️ Constraints:
- 1 <= nums.length <= 200
- 1 <= nums[i] <= 100
*/


/* ================================================================
   ✅ Approach 1: Dynamic Programming (Subset Sum)
   ================================================================
   🔍 Intuition:
   - The problem reduces to checking if there exists a subset
     whose sum equals half of the total array sum.
   - Use a 1D DP array `possible` where `possible[i]` means
     whether a subset sum of `i` is possible using given elements.
   - Iterate backwards to prevent overwriting results of the same iteration.

   ⏱️ Complexity:
   - Time:  O(n * target)   where target = totalSum / 2
   - Space: O(target)
================================================================ */

class Solution {
public:
    bool canPartition(vector<int>& elements) {
        int totalSum = accumulate(elements.begin(), elements.end(), 0);

        // If sum is odd, it can't be split equally
        if (totalSum % 2 != 0) return false;

        int halfSum = totalSum / 2;
        vector<bool> possible(halfSum + 1, false);
        possible[0] = true;

        for (int value : elements) {
            for (int current = halfSum; current >= value; current--) {
                if (possible[current - value]) 
                    possible[current] = true;

                // Early exit if halfSum already achieved
                if (possible[halfSum]) return true;
            }
        }

        return possible[halfSum];
    }
};
