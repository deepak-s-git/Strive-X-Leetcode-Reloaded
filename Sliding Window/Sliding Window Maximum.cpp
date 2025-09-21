/*
Problem: Sliding Window Maximum (LeetCode #239)
-----------------------------------------------
You are given an array of integers nums, and there is a sliding window 
of size k which moves from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window 
moves right by one position. Return the max sliding window.

Examples:
---------
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]

Input: nums = [1], k = 1
Output: [1]

Constraints:
------------
- 1 <= nums.length <= 10^5
- -10^4 <= nums[i] <= 10^4
- 1 <= k <= nums.length
*/


// -----------------------------------------------------------------------------
// Approach 1: Monotonic Deque (Optimal)
// -----------------------------------------------------------------------------
// Idea:
// - Use a deque to store indices of useful elements in decreasing order.
// - The front of the deque always holds the index of the maximum element 
//   for the current window.
// - For each element at index i:
//     1. Remove elements from the back while nums[i] >= nums[dq.back()].
//     2. Push current index into deque.
//     3. Remove front if it’s out of this window (i - k).
//     4. Record result when i >= k - 1.
//
// Time Complexity: O(n)  (each element pushed & popped at most once)
// Space Complexity: O(k) (deque stores at most k indices)
//
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;                 // stores indices of useful elements
        vector<int> ans(n - k + 1);    // result array

        for (int i = 0; i < n; i++) {
            // Maintain decreasing order in deque
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);

            // Remove indices that are out of this window
            if (dq.front() <= i - k) {
                dq.pop_front();
            }

            // Record max for each valid window
            if (i >= k - 1) {
                ans[i - k + 1] = nums[dq.front()];
            }
        }
        return ans;
    }
};