/*
Problem: Top K Frequent Elements (LeetCode #347)
-------------------------------------------------
Given an integer array `nums` and an integer `k`, return the `k` most 
frequent elements. You may return the answer in any order.

Example:
--------
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Explanation:
- 1 appears 3 times
- 2 appears 2 times
- 3 appears 1 time
The top 2 frequent elements are [1,2].

Constraints:
------------
- 1 <= nums.length <= 10^5
- k is in the range [1, number of unique elements in nums]
- It is guaranteed that the answer is unique.
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Max-Heap
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Count frequency of each element using a hash map.
// - Use a max-heap (priority queue) to store elements by frequency.
// - Pop k elements from the heap to get top k frequent.
//
// ⏱️ Time Complexity: O(N log N) — building heap + k pops
// 📦 Space Complexity: O(N) — hash map + heap
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int val : nums) {
            freq[val]++;
        }

        priority_queue<pair<int,int>> heap; // {frequency, value}
        for (auto& [num, count] : freq) {
            heap.push({count, num});
        }

        vector<int> result;
        while (k-- > 0 && !heap.empty()) {
            result.push_back(heap.top().second);
            heap.pop();
        }
        return result;
    }
};
