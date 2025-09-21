/*
Problem: Minimum Size Subarray Sum (LeetCode #209)
---------------------------------------------------
Given an array of positive integers nums and a positive integer target, 
return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] 
of which the sum is greater than or equal to target. If no such subarray exists, return 0.

Example:
--------
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Constraints:
------------
- 1 <= target <= 10^9
- 1 <= nums.length <= 10^5
- 1 <= nums[i] <= 10^4
*/

// -----------------------------------------------------------------------------
// Approach: Sliding Window
// -----------------------------------------------------------------------------
// Idea:
// - Expand the window by moving `right` pointer and adding nums[right] to currSum.
// - As soon as currSum >= target, shrink the window from the left
//   until currSum < target, updating minLen at each step.
// - If no valid subarray is found, return 0.
//
// Time Complexity: O(n)  -> each element is visited at most twice
// Space Complexity: O(1) -> only extra variables used
//
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = n + 1;  // Initialize with max possible + 1
        int left = 0;
        int currSum = 0;

        for (int right = 0; right < n; right++) {
            currSum += nums[right];

            // Shrink window while sum >= target
            while (currSum >= target) {
                minLen = min(minLen, right - left + 1);
                currSum -= nums[left];
                left++;
            }
        }

        // If minLen was not updated, return 0
        return (minLen == n + 1) ? 0 : minLen;
    }
};
