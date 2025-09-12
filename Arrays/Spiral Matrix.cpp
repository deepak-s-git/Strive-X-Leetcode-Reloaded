/*
Problem: Spiral Matrix (LeetCode #54)
--------------------------------------
Given an m x n matrix, return all elements of the matrix in spiral order.

Examples:
----------
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints:
-------------
- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 10
- -100 <= matrix[i][j] <= 100
*/


// -----------------------------------------------------------------------------
// Approach: Boundary Simulation
// -----------------------------------------------------------------------------
// Idea:
// - Maintain 4 boundaries: srow (start row), scol (start col),
//   erow (end row), ecol (end col).
// - Traverse in order: 
//   1. Top row (left → right)
//   2. Right column (top → bottom)
//   3. Bottom row (right → left) if srow < erow
//   4. Left column (bottom → top) if scol < ecol
// - After each pass, shrink the corresponding boundary.
// - Stop when srow > erow or scol > ecol.
//
// Time Complexity: O(m * n)
// Space Complexity: O(1) (ignoring output vector)
//
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;
        vector<int> ans;

        while (srow <= erow && scol <= ecol) {
            // Traverse top row
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(mat[srow][j]);
            }

            // Traverse right column
            for (int i = srow + 1; i <= erow; i++) {
                ans.push_back(mat[i][ecol]);
            }

            // Traverse bottom row
            for (int j = ecol - 1; j >= scol; j--) {
                if (srow == erow) break; // avoid double-counting
                ans.push_back(mat[erow][j]);
            }

            // Traverse left column
            for (int i = erow - 1; i >= srow + 1; i--) {
                if (scol == ecol) break; // avoid double-counting
                ans.push_back(mat[i][scol]);
            }

            // Shrink boundaries
            srow++; erow--;
            scol++; ecol--;
        }

        return ans;
    }
};
