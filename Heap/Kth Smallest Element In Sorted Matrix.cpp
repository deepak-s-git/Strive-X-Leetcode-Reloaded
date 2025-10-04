/*
Problem: Kth Smallest Element in a Sorted Matrix (LeetCode #378)
-----------------------------------------------------------------
Given an n x n matrix where each row and each column is sorted in ascending order,
return the k-th smallest element in the matrix.

Example:
--------
Input:
matrix = [
  [1, 5, 9],
  [10, 11, 13],
  [12, 13, 15]
]
k = 8

Output: 13

Explanation:
The elements in sorted order are:
[1, 5, 9, 10, 11, 12, 13, 13, 15]
The 8th smallest is 13.

Constraints:
------------
- n == matrix.length == matrix[i].length
- 1 <= n <= 300
- -10^9 <= matrix[i][j] <= 10^9
- All rows and columns are sorted in non-decreasing order.
- 1 <= k <= n^2
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Max Heap (Brute Force Heap Approach)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Insert all elements into a max heap of size `k`.
// - If heap size exceeds `k`, remove the largest element.
// - After processing all elements, the heap's top is the k-th smallest.
//
// ⏱️ Time Complexity: O(n^2 log k)
// 📦 Space Complexity: O(k)
// -----------------------------------------------------------------------------
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size(), cols = matrix[0].size();
        priority_queue<int> heap;  // max heap

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                heap.push(matrix[i][j]);
                if ((int)heap.size() > k) heap.pop();  // keep size <= k
            }
        }
        return heap.top();
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 2: Min Heap with Row-wise Traversal (Optimized O(k log n))
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Use a min-heap to always pop the smallest available element.
// - Initially, push the first element of each row into the heap.
// - Each time we pop the smallest, push the next element from that row.
// - After `k` pops, the popped element is the k-th smallest.
//
// ⏱️ Time Complexity: O(k log n) — heap size at most n
// 📦 Space Complexity: O(n)
// -----------------------------------------------------------------------------
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size(), cols = matrix[0].size();
        int ans = -1;

        using Node = vector<int>; // {val, row, col}
        priority_queue<Node, vector<Node>, greater<>> heap;

        // Insert first element of each row
        for (int i = 0; i < min(rows, k); i++) {
            heap.push({matrix[i][0], i, 0});
        }

        // Extract k elements
        for (int step = 1; step <= k; step++) {
            auto cur = heap.top(); 
            heap.pop();
            int val = cur[0], r = cur[1], c = cur[2];
            ans = val;
            if (c + 1 < cols) {
                heap.push({matrix[r][c + 1], r, c + 1});
            }
        }
        return ans;
    }
};
