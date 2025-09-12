/*
Problem: Rotate Image (LeetCode #48)
--------------------------------------
You are given an n x n 2D matrix representing an image. 
Rotate the image by 90 degrees (clockwise), in-place.

Examples:
----------
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

Constraints:
-------------
- n == matrix.length == matrix[i].length
- 1 <= n <= 20
- -1000 <= matrix[i][j] <= 1000
*/


// -----------------------------------------------------------------------------
// Approach: Flip + Transpose
// -----------------------------------------------------------------------------
// Idea:
// To rotate the matrix 90° clockwise in place:
// 1. Reverse the matrix vertically (swap top row with bottom row).
// 2. Transpose the matrix (swap across main diagonal).
//
// Example (n = 3):
// Before:          After Vertical Flip:     After Transpose (Final):
// 1 2 3            7 8 9                    7 4 1
// 4 5 6    --->    4 5 6    --->            8 5 2
// 7 8 9            1 2 3                    9 6 3
//
// Time Complexity: O(n^2)
// Space Complexity: O(1) (in-place)
//
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int edgeLen = matrix.size();

        // Step 1: Reverse vertically (swap rows)
        int top = 0, bottom = edgeLen - 1;
        while (top < bottom) {
            for (int col = 0; col < edgeLen; col++) {
                swap(matrix[top][col], matrix[bottom][col]);
            }
            top++;
            bottom--;
        }

        // Step 2: Transpose (swap across diagonal)
        for (int row = 0; row < edgeLen; row++) {
            for (int col = row + 1; col < edgeLen; col++) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
};
