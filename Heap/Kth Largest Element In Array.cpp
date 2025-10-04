/*
Problem: Kth Largest Element in an Array (LeetCode #215)
---------------------------------------------------------
Given an integer array `nums` and an integer `k`, return the k-th largest 
element in the array.

Example:
--------
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Explanation:
- The sorted array is [1,2,3,4,5,6]
- The 2nd largest element is 5

Constraints:
------------
- 1 <= k <= nums.length <= 10^5
- -10^4 <= nums[i] <= 10^4
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Max-Heap (Priority Queue)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Push all elements into a max-heap.
// - Pop the top element k-1 times, the next top is the k-th largest.
//
// ⏱️ Time Complexity: O(N log N) — N = nums.size(), heap push/pop operations
// 📦 Space Complexity: O(N) — max-heap storing all elements
// -----------------------------------------------------------------------------
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> p; // max-heap

        for (int i = 0; i < n; i++) {
            p.push(nums[i]);
        }

        while (k > 1) {
            p.pop();
            k--;
        }
        return p.top();
    }
};
