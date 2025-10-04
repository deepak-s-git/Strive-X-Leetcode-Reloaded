/*
Problem: Find K Pairs with Smallest Sums (LeetCode #373)
--------------------------------------------------------
You are given two integer arrays `nums1` and `nums2`, both sorted in non-decreasing order, 
and an integer `k`. 

Return the `k` pairs `(u, v)` such that:
- u is from `nums1`
- v is from `nums2`
- The sum `u + v` is among the k smallest possible sums.

Example:
--------
Input:
nums1 = [1, 7, 11]
nums2 = [2, 4, 6]
k = 3

Output:
[[1, 2], [1, 4], [1, 6]]

Explanation:
The pairs are:
1+2=3, 1+4=5, 1+6=7, 7+2=9, 7+4=11, 7+6=13, 11+2=13, 11+4=15, 11+6=17
The 3 smallest sums are: 3, 5, 7.

Constraints:
------------
- 1 <= nums1.length, nums2.length <= 10^5
- -10^9 <= nums1[i], nums2[j] <= 10^9
- 1 <= k <= 10^4
- nums1 and nums2 are sorted in non-decreasing order
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Min-Heap (Best O(k log n) Approach)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Both arrays are sorted. The smallest sums will involve the smallest elements.
// - Start by pairing each element of `nums1` with the first element of `nums2`.
// - Use a min-heap to always extract the pair with the smallest sum.
// - After popping a pair (u, v2), push the next pair (u, v2+1) into the heap.
//
// 📊 Steps:
// 1. Push pairs (nums1[i] + nums2[0], index_in_nums2) for each nums1[i].
// 2. Pop the smallest sum from the heap and record the pair.
// 3. If possible, push the next pair from the same row (same nums1[i], next nums2 element).
// 4. Repeat until we've found `k` pairs.
//
// ⏱️ Time Complexity: O(k log n)   — where n = min(k, size of nums1)
// 📦 Space Complexity: O(n)        — size of heap
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        // Step 1: Pair every nums1[i] with nums2[0]
        for (int num : nums1) {
            minHeap.push({num + nums2[0], 0});
        }

        // Step 2: Extract smallest pairs
        while (k-- && !minHeap.empty()) {
            auto [sum, idx2] = minHeap.top();
            minHeap.pop();

            int num1 = sum - nums2[idx2];   // Recover num1 from (sum - nums2[idx2])
            int num2 = nums2[idx2];
            result.push_back({num1, num2});

            // Step 3: Push next element from nums2 with the same num1
            if (idx2 + 1 < nums2.size()) {
                minHeap.push({num1 + nums2[idx2 + 1], idx2 + 1});
            }
        }

        return result;
    }
};
