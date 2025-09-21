/*
Problem: Maximum Average Subarray I (LeetCode #643)
---------------------------------------------------
Given an array nums consisting of n integers, find the contiguous subarray 
of length k that has the maximum average value, and return this value.

You need to solve it in O(n) time complexity.

Example:
--------
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51/4 = 12.75

Constraints:
------------
- 1 <= k <= nums.length <= 10^5
- -10^4 <= nums[i] <= 10^4
*/

// -----------------------------------------------------------------------------
// Approach: Sliding Window
// -----------------------------------------------------------------------------
// Idea:
// - First compute the sum of the first k elements.
// - Then slide the window across the array by adding the new element and
//   removing the first element of the previous window.
// - Keep track of the maximum window sum encountered.
// - Finally, return maxSum / k as a double.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currSum = 0, maxSum = 0;

        // Step 1: Sum of the first window
        for (int i = 0; i < k; i++) {
            currSum += nums[i];
        }
        maxSum = currSum;

        // Step 2: Slide the window
        for (int i = k; i < nums.size(); i++) {
            currSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, currSum);
        }

        // Step 3: Return average
        return maxSum / k;
    }
};
