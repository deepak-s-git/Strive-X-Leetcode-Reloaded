/*
Problem: Rotate Image (LeetCode #48)
-------------------------------------
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).

You must rotate the image in-place.

Example:
--------
Input:
matrix = [
 [1,2,3],
 [4,5,6],
 [7,8,9]
]

Output:
[
 [7,4,1],
 [8,5,2],
 [9,6,3]
]

Constraints:
------------
- n == matrix.length == matrix[i].length
- 1 <= n <= 20
- -1000 <= matrix[i][j] <= 1000
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Reverse Rows + Transpose (In-Place)
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// To rotate matrix 90° clockwise:
// 1️⃣ Reverse the matrix vertically (swap top row with bottom row).
// 2️⃣ Transpose the matrix (swap matrix[row][col] with matrix[col][row]).
//
// Why this works?
// - Reversing flips the matrix upside down.
// - Transposing converts rows into columns.
// - Combined effect = 90° clockwise rotation.
//
// ⏱ Time Complexity: O(n²)
// 📦 Space Complexity: O(1) (in-place)
// -----------------------------------------------------------------------------
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int edgeLen = matrix.size();

        int top = 0, bottom = edgeLen - 1;

        // 🔁 Step 1: Reverse rows (vertical flip)
        while(top < bottom){
            for(int col = 0; col < edgeLen; col++){
                swap(matrix[top][col], matrix[bottom][col]);
            }
            top++;
            bottom--;
        }

        // 🔁 Step 2: Transpose the matrix
        for(int row = 0; row < edgeLen; row++){
            for(int col = row + 1; col < edgeLen; col++){
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
};