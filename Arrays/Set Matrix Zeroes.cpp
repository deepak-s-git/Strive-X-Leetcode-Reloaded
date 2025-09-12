/*
Problem: Set Matrix Zeroes (LeetCode #73)
------------------------------------------
Given an m x n integer matrix, if an element is 0, set its entire row and 
column to 0. Do it in-place.

Examples:
----------
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Constraints:
-------------
- m == matrix.length
- n == matrix[0].length
- 1 <= m, n <= 200
- -2^31 <= matrix[i][j] <= 2^31 - 1
*/


// -----------------------------------------------------------------------------
// Approach 0: Extra Matrix Copy (Brute Force)
// -----------------------------------------------------------------------------
// Idea:
// - Copy matrix into another matrix2.
// - When encountering a 0 in original matrix, set its row & col to 0 in matrix2.
// - Copy matrix2 back to matrix.
//
// Time Complexity: O(m * n * (m + n)) ≈ O(m*n^2)
// Space Complexity: O(m*n) (full extra matrix)
//
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> matrix2(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix2[i][j] = matrix[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < n; k++) matrix2[i][k] = 0;
                    for (int k = 0; k < m; k++) matrix2[k][j] = 0;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = matrix2[i][j];
            }
        }
    }
};


// -----------------------------------------------------------------------------
// Approach 1: Row/Column Markers (Extra Arrays)
// -----------------------------------------------------------------------------
// Idea:
// - Track which rows & columns must be zeroed using two arrays.
// - In second pass, zero out elements where row or col is marked.
//
// Time Complexity: O(m * n)
// Space Complexity: O(m + n)
//
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rowsArr(m, 1), colsArr(n, 1);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rowsArr[i] = 0;
                    colsArr[j] = 0;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rowsArr[i] == 0 || colsArr[j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


// -----------------------------------------------------------------------------
// Approach 2: In-Place Using First Row & Col as Markers (Optimal)
// -----------------------------------------------------------------------------
// Idea:
// - Use the first row and first column as marker storage.
// - First detect if row0/col0 themselves should be zeroed.
// - For other cells: if matrix[i][j] == 0, mark matrix[i][0] & matrix[0][j] = 0.
// - In second pass, zero out based on markers.
// - Finally, zero out row0/col0 if needed.
//
// Time Complexity: O(m * n)
// Space Complexity: O(1) (only flags)
//
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool row0 = false, col0 = false;

        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) row0 = true;
        }
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) col0 = true;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (row0) {
            for (int j = 0; j < n; j++) matrix[0][j] = 0;
        }
        if (col0) {
            for (int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
};
