/*
Problem: Set Matrix Zeroes (LeetCode #73)
-----------------------------------------
Given an m x n integer matrix `matrix`, if an element is 0,
set its entire row and column to 0.

You must do it in-place.

Example:
--------
Input:
matrix = [
 [1,1,1],
 [1,0,1],
 [1,1,1]
]

Output:
[
 [1,0,1],
 [0,0,0],
 [1,0,1]
]

Constraints:
------------
- m == matrix.length
- n == matrix[0].length
- 1 <= m, n <= 200
- -2^31 <= matrix[i][j] <= 2^31 - 1
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Extra Matrix (Brute Force Copy)
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Create a copy of the matrix.
// - Whenever a 0 is found, mark entire row & column as 0 in copy.
// - Copy back result.
//
// ⏱ Time Complexity: O(m * n * (m + n))
// 📦 Space Complexity: O(m * n)
// -----------------------------------------------------------------------------
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> matrix2(m, vector<int>(n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                matrix2[i][j] = matrix[i][j];
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    for(int k = 0; k < n; k++) matrix2[i][k] = 0;
                    for(int k = 0; k < m; k++) matrix2[k][j] = 0;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = matrix2[i][j];
            }
        }
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 2: Extra Row & Column Arrays
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Maintain two arrays: rowsArr and colsArr.
// - If matrix[i][j] == 0 → mark rowsArr[i] = 0 and colsArr[j] = 0.
// - In second pass, set matrix[i][j] = 0 if row or column marked.
//
// ⏱ Time Complexity: O(m * n)
// 📦 Space Complexity: O(m + n)
// -----------------------------------------------------------------------------
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rowsArr(m, 1), colsArr(n, 1);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    rowsArr[i] = 0;
                    colsArr[j] = 0;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rowsArr[i] == 0 || colsArr[j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 3: Optimal (Use First Row & Column as Markers)
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Use first row and first column to store zero markers.
// - Two flags (row0, col0) track whether first row/col should be zero.
// - First pass: mark rows & columns.
// - Second pass: update inner matrix.
// - Finally, update first row & column if needed.
//
// ⏱ Time Complexity: O(m * n)
// 📦 Space Complexity: O(1)
// -----------------------------------------------------------------------------
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