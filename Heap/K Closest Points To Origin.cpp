/*
Problem: K Closest Points to Origin (LeetCode #973)
---------------------------------------------------
Given an array of points where points[i] = [xi, yi] and an integer k, 
return the k closest points to the origin (0, 0).

The distance is calculated using Euclidean distance: sqrt(x^2 + y^2).
The answer can be returned in any order.

Example:
--------
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]

Explanation:
Distance of (1,3) = sqrt(1 + 9) = sqrt(10)
Distance of (-2,2) = sqrt(4 + 4) = sqrt(8)
The closest point is [-2,2].

Constraints:
------------
- 1 <= k <= points.length <= 10^4
- -10^4 <= xi, yi <= 10^4
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Max-Heap (Priority Queue)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Maintain a max-heap of size k storing points by their distance squared from origin.
// - For each new point:
//   - If heap size < k → push.
//   - Else if point is closer than heap top → replace top.
// - At the end, heap contains k closest points.
//
// ⏱️ Time Complexity: O(N log k)
// 📦 Space Complexity: O(k)
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> heap;  // {distance, x, y}
        for (auto& pt : points) {
            int x = pt[0], y = pt[1];
            heap.push({x*x + y*y, x, y});
            if (heap.size() > k) heap.pop();
        }

        vector<vector<int>> result(k);
        for (int i = 0; i < k; ++i) {
            vector<int> top = heap.top();
            heap.pop();
            result[i] = {top[1], top[2]};
        }
        return result;
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 2: Heapify (Using make_heap)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Convert all points into a heap array with negative distances to simulate max-heap.
// - Use make_heap + pop_heap to extract k closest points.
//
// ⏱️ Time Complexity: O(N + k log N)
// 📦 Space Complexity: O(N)
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> heapArr;
        for (auto& pt : points) {
            int x = pt[0], y = pt[1];
            heapArr.push_back({-x*x - y*y, x, y});
        }

        make_heap(heapArr.begin(), heapArr.end());
        vector<vector<int>> result;
        while (k--) {
            vector<int> top = heapArr[0];
            pop_heap(heapArr.begin(), heapArr.end());
            heapArr.pop_back();
            result.push_back({top[1], top[2]});
        }
        return result;
    }
};
