/*
Problem: Spiral Matrix (LeetCode #54)
-------------------------------------
Given an m x n matrix, return all elements of the matrix in spiral order.

Example:
--------
Input:
matrix = [
 [1,2,3],
 [4,5,6],
 [7,8,9]
]

Output:
[1,2,3,6,9,8,7,4,5]

Constraints:
------------
- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 10
- -100 <= matrix[i][j] <= 100
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Boundary Traversal (Layer by Layer)
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Maintain 4 boundaries:
//      srow (start row), erow (end row)
//      scol (start column), ecol (end column)
// - Traverse in 4 directions:
//      → Left to Right
//      ↓ Top to Bottom
//      ← Right to Left
//      ↑ Bottom to Top
// - After completing one layer, shrink boundaries.
// - Stop when boundaries cross.
//
// ⏱ Time Complexity: O(m * n)
// 📦 Space Complexity: O(1) extra (excluding output)
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;
        vector<int> ans;

        while(srow <= erow && scol <= ecol){

            // ➡ Traverse top row
            for(int j = scol; j <= ecol; j++){
                ans.push_back(matrix[srow][j]);
            }

            // ⬇ Traverse right column
            for(int i = srow + 1; i <= erow; i++){
                ans.push_back(matrix[i][ecol]);
            }

            // ⬅ Traverse bottom row
            for(int j = ecol - 1; j >= scol; j--){
                if(srow == erow) break;
                ans.push_back(matrix[erow][j]);
            }

            // ⬆ Traverse left column
            for(int i = erow - 1; i >= srow + 1; i--){
                if(scol == ecol) break;
                ans.push_back(matrix[i][scol]);
            }

            srow++; 
            erow--;
            scol++; 
            ecol--;
        }
        return ans;
    }
};