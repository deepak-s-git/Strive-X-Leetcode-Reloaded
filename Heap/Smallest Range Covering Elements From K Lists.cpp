/*
Problem: Smallest Range Covering Elements from K Lists (LeetCode #632)
-----------------------------------------------------------------------
You are given `k` sorted integer lists. Your task is to find the smallest range [L, R]
that includes at least one number from each of the `k` lists.

Example:
--------
Input:
lists = [
  [4,10,15,24,26],
  [0,9,12,20],
  [5,18,22,30]
]

Output:
[20,24]

Explanation:
-----------
- 20 is from list 2, 24 is from list 1, and 22 is from list 3.
- The range [20, 24] contains at least one element from each list.
- This is the smallest such range.

Constraints:
------------
- k == lists.length
- 1 <= k <= 3500
- 1 <= lists[i].length <= 50
- -10^5 <= lists[i][j] <= 10^5
- lists[i] is sorted in non-decreasing order
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Min-Heap + Sliding Window (O(N log K))
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Use a min-heap to always pick the smallest current element among all lists.
// - Track the current maximum element among the selected ones.
// - The current range is [minHeap.top(), currentMax].
// - Pop the min element and push the next from its list to slide the window.
// - Keep updating the best range if the current one is smaller.
//
// 📊 Complexity:
// - ⏱️ Time Complexity: O(N log K) — each insertion/pop in heap takes log K
// - 📦 Space Complexity: O(K) — storing one element from each list
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& lists) {
        // Min-heap: stores {value, {listIndex, elementIndex}}
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > minHeap;

        int currentMax = INT_MIN;

        // Step 1: Push first element of each list and track the current max
        for (int i = 0; i < lists.size(); i++) {
            minHeap.push({lists[i][0], {i, 0}});
            currentMax = max(currentMax, lists[i][0]);
        }

        // Step 2: Initialize best range
        int currentMin = minHeap.top().first;
        vector<int> bestRange = {currentMin, currentMax};

        // Step 3: Continuously update range by popping smallest and adding next element
        while (minHeap.size() == lists.size()) {
            auto topElement = minHeap.top();
            minHeap.pop();

            int value = topElement.first;
            int listIndex = topElement.second.first;
            int elementIndex = topElement.second.second;

            // Push next element from the same list
            if (elementIndex + 1 < lists[listIndex].size()) {
                int nextValue = lists[listIndex][elementIndex + 1];
                minHeap.push({nextValue, {listIndex, elementIndex + 1}});
                currentMax = max(currentMax, nextValue);

                // Update min
                currentMin = minHeap.top().first;

                // Update best range if smaller
                if (currentMax - currentMin < bestRange[1] - bestRange[0]) {
                    bestRange = {currentMin, currentMax};
                }
            }
        }

        return bestRange;
    }
};
