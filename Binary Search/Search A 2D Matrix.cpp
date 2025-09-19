/*
Problem: Search a 2D Matrix (LeetCode #74)
------------------------------------------
You are given an m x n integer matrix with the following properties:
- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in the matrix, or false otherwise.

Examples:
---------
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Constraints:
-------------
- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 100
- -10^4 <= matrix[i][j] <= 10^4
*/


// -----------------------------------------------------------------------------
// Approach: Binary Search (Two-Level)
// -----------------------------------------------------------------------------
// Idea:
// 1. First, use binary search on the rows to find the row that may contain target.
//    - If target lies between matrix[midRow][0] and matrix[midRow][n-1], 
//      then it must be inside that row.
// 2. Once the candidate row is found, perform a binary search inside that row.
//
// Time Complexity: O(log m + log n)   // binary search on rows + binary search in row
// Space Complexity: O(1)
//
class Solution {
public:
    bool searchInRow(vector<vector<int>>& matrix, int target, int row) {
        int n = matrix[0].size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (target == matrix[row][mid]) {
                return true;
            } else if (target > matrix[row][mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int startRow = 0, endRow = m - 1;
        while (startRow <= endRow) {
            int midRow = startRow + (endRow - startRow) / 2;

            if (target >= matrix[midRow][0] && target <= matrix[midRow][n - 1]) {
                return searchInRow(matrix, target, midRow);
            } else if (target > matrix[midRow][n - 1]) {
                startRow = midRow + 1;
            } else {
                endRow = midRow - 1;
            }
        }
        return false;
    }
};
