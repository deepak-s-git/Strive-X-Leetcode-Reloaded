/*
Problem: Sliding Window Median (LeetCode #480)
----------------------------------------------
Given an array `nums` and a window size `k`, return the median of each sliding window.

The median is the middle element in an ordered list of numbers. If the list size is even,
the median is the average of the two middle elements.

Example:
--------
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [1.0, -1.0, -1.0, 3.0, 5.0, 6.0]

Explanation:
Window positions and medians:
- [1, 3, -1] -> median = 1.0
- [3, -1, -3] -> median = -1.0
- [-1, -3, 5] -> median = -1.0
- [-3, 5, 3] -> median = 3.0
- [5, 3, 6] -> median = 5.0
- [3, 6, 7] -> median = 6.0

Constraints:
------------
- 1 <= k <= nums.length <= 10^5
- -2^31 <= nums[i] <= 2^31 - 1
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Two Heaps + Lazy Deletion
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Maintain two heaps:
//   1. `left` (max-heap): stores the smaller half of the window
//   2. `right` (min-heap): stores the larger half
// - Balance heaps such that:
//   - |size(left) - size(right)| ≤ 1
//   - All elements in `left` ≤ all elements in `right`
// - Median is:
//   - If k is odd → top of `left`
//   - If k is even → average of tops of `left` and `right`
//
// ⚠️ Challenge: Removing elements leaving the sliding window is not trivial.
// - We use a `pending` map to "mark" elements for lazy deletion.
// - Before accessing heap tops, we pop elements that are marked as removed.
//
// 📊 Complexity:
// - ⏱️ Time Complexity: O(N log K) (each insertion/removal is O(log K))
// - 📦 Space Complexity: O(K) (for heaps and map)
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        int n = nums.size();

        // Lazy deletion map: keeps count of elements to be removed
        unordered_map<int, int> pending;
        
        // Two heaps: left = max-heap, right = min-heap
        priority_queue<int> left; 
        priority_queue<int, vector<int>, greater<int>> right;
        
        // Step 1: Initialize the first window
        for (int i = 0; i < k; i++) left.push(nums[i]);
        for (int i = 0; i < (k / 2); i++) {  // rebalance
            right.push(left.top());
            left.pop();
        }

        // Step 2: Slide the window across the array
        for (int i = k; i < n; i++) {
            // ✅ Add current median before sliding
            if (k & 1) result.push_back(left.top() * 1.0);
            else result.push_back(((double)left.top() + (double)right.top()) / 2);

            int removeVal = nums[i - k]; // element leaving window
            int addVal = nums[i];        // element entering window
            int balance = 0;

            // Step 3: Remove outgoing element
            if (removeVal <= left.top()) {
                balance--;
                if (removeVal == left.top()) left.pop();
                else pending[removeVal]++;
            } else {
                balance++;
                if (removeVal == right.top()) right.pop();
                else pending[removeVal]++;
            }

            // Step 4: Add incoming element
            if (!left.empty() && addVal <= left.top()) {
                left.push(addVal);
                balance++;
            } else {
                right.push(addVal);
                balance--;
            }

            // Step 5: Rebalance heaps if needed
            if (balance < 0) {
                left.push(right.top());
                right.pop();
            } else if (balance > 0) {
                right.push(left.top());
                left.pop();
            }

            // Step 6: Clean up lazy deleted elements
            while (!left.empty() && pending[left.top()]) {
                pending[left.top()]--;
                left.pop();
            }
            while (!right.empty() && pending[right.top()]) {
                pending[right.top()]--;
                right.pop();
            }
        }

        // ✅ Add median for the final window
        if (k & 1) result.push_back(left.top() * 1.0);
        else result.push_back(((double)left.top() + (double)right.top()) / 2.0);

        return result;
    }
};
