/*
Problem: Kth Smallest Element in a Sorted Matrix (LeetCode #378)
-----------------------------------------------------------------
Given an n x n matrix where each row and each column is sorted in 
ascending order, return the kth smallest element in the matrix.

Note:
- It is the kth smallest element in the sorted order, not the kth 
  distinct element.

Examples:
----------
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13

Input: matrix = [[-5]], k = 1
Output: -5

Constraints:
-------------
- n == matrix.length
- n == matrix[i].length
- 1 <= n <= 300
- -10^9 <= matrix[i][j] <= 10^9
- All the rows and columns of matrix are sorted in non-decreasing order
- 1 <= k <= n^2
*/


// -----------------------------------------------------------------------------
// Approach 0: Brute Force
// -----------------------------------------------------------------------------
// Idea:
// - Flatten matrix into 1D array.
// - Sort it and return arr[k-1].
//
// Time Complexity: O(n^2 log n)
// Space Complexity: O(n^2)
//
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> arr;
        for (auto& row : matrix) {
            arr.insert(arr.end(), row.begin(), row.end());
        }
        sort(arr.begin(), arr.end());
        return arr[k-1];
    }
};

// -----------------------------------------------------------------------------
// Approach 2: Binary Search on Value Range
// -----------------------------------------------------------------------------
// Idea:
// - The kth smallest lies between smallest (matrix[0][0]) 
//   and largest (matrix[n-1][n-1]).
// - Binary search this value range.
// - For mid, count how many elements ≤ mid using upper_bound on each row.
// - Adjust range until st == end.
// - Works since rows are sorted.
//
// Time Complexity: O(n log(max-min))
// Space Complexity: O(1)
//
// Note: Faster than heap when n is large but k is also large.
//
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int st = matrix[0][0];          // smallest value
        int end = matrix[n-1][n-1];     // largest value

        while (st < end) {
            int mid = st + (end - st) / 2;
            int count = 0;

            // count how many numbers ≤ mid
            for (int i = 0; i < n; i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) 
                         - matrix[i].begin();
            }

            if (count < k) {
                st = mid + 1;
            } else {
                end = mid;
            }
        }
        return st;
    }
};
