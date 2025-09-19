/*
Problem: Search a 2D Matrix II (LeetCode #240)
----------------------------------------------
Write an efficient algorithm that searches for a target value in an m x n integer 
matrix. The matrix has the following properties:
- Integers in each row are sorted in ascending order.
- Integers in each column are sorted in ascending order.

Examples:
---------
Input: matrix = [[1,4,7,11,15],
                 [2,5,8,12,19],
                 [3,6,9,16,22],
                 [10,13,14,17,24],
                 [18,21,23,26,30]], target = 5
Output: true

Input: matrix = [[1,4,7,11,15],
                 [2,5,8,12,19],
                 [3,6,9,16,22],
                 [10,13,14,17,24],
                 [18,21,23,26,30]], target = 20
Output: false

Constraints:
-------------
- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 300
- -10^9 <= matrix[i][j] <= 10^9
*/


// -----------------------------------------------------------------------------
// Approach: Staircase Search (Top-Right Corner)
// -----------------------------------------------------------------------------
// Idea:
// - Start from the top-right element (row=0, col=n-1).
// - If current element == target → return true.
// - If current element > target → move left (col--).
// - If current element < target → move down (row++).
// - This works because rows and columns are sorted.
//
// Time Complexity: O(m + n)   // worst case traverse at most one full row + column
// Space Complexity: O(1)
//
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int row = 0, col = n - 1;

        while (row < m && col >= 0) {
            if (target == matrix[row][col]) {
                return true;
            } else if (target < matrix[row][col]) {
                col--;  // move left
            } else {
                row++;  // move down
            }
        }
        return false;
    }
};
