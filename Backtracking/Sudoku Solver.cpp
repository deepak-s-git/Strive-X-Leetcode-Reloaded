/*
Problem: Sudoku Solver (LeetCode #37)
-------------------------------------
Write a program to solve a 9x9 Sudoku puzzle by filling the empty cells.

- A Sudoku solution must satisfy:
  1. Each row contains digits 1–9 without repetition.
  2. Each column contains digits 1–9 without repetition.
  3. Each 3x3 sub-box contains digits 1–9 without repetition.

- The '.' character represents empty cells.

Example:
--------
Input:
board = 
[["5","3",".",".","7",".",".",".","."],
 ["6",".",".","1","9","5",".",".","."],
 [".","9","8",".",".",".",".","6","."],
 ["8",".",".",".","6",".",".",".","3"],
 ["4",".",".","8",".","3",".",".","1"],
 ["7",".",".",".","2",".",".",".","6"],
 [".","6",".",".",".",".","2","8","."],
 [".",".",".","4","1","9",".",".","5"],
 [".",".",".",".","8",".",".","7","9"]]

Output: (one valid solution)
[["5","3","4","6","7","8","9","1","2"],
 ["6","7","2","1","9","5","3","4","8"],
 ["1","9","8","3","4","2","5","6","7"],
 ["8","5","9","7","6","1","4","2","3"],
 ["4","2","6","8","5","3","7","9","1"],
 ["7","1","3","9","2","4","8","5","6"],
 ["9","6","1","5","3","7","2","8","4"],
 ["2","8","7","4","1","9","6","3","5"],
 ["3","4","5","2","8","6","1","7","9"]]

Constraints:
------------
- board.length == 9
- board[i].length == 9
- board[i][j] is a digit or '.'
- There is exactly one solution
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Backtracking
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - For each empty cell ('.'), try placing digits '1' to '9'.
// - Before placing a digit, check if it's valid using Sudoku rules:
//   - Not already present in the current row
//   - Not already present in the current column
//   - Not already present in the current 3x3 subgrid
// - If a digit is valid, place it and move to the next cell recursively.
// - If no digit is valid, backtrack and try a different digit in previous cells.
//
// ⚙️ Steps:
// 1. Traverse board cell by cell.
// 2. When '.' is found, try placing all digits from '1' to '9'.
// 3. Validate with `isSafe()` function.
// 4. If placing a digit leads to a solution → done.
// 5. Else → backtrack and try the next digit.
//
// ⏱️ Time Complexity: O(9^(81)) worst-case (very rare in practice)
// 📦 Space Complexity: O(1) (in-place board modification + recursion stack)
// -----------------------------------------------------------------------------
class Solution {
public:
    // ✅ Check if placing `dig` is valid at (row, col)
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
        // Check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == dig) return false;
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == dig) return false;
        }

        // Check 3x3 subgrid
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;
        for (int i = srow; i < srow + 3; i++) {
            for (int j = scol; j < scol + 3; j++) {
                if (board[i][j] == dig) return false;
            }
        }
        return true;
    }

    // 🔁 Recursive solver with backtracking
    bool solver(vector<vector<char>>& board, int row, int col) {
        // ✅ Base case: All rows processed
        if (row == 9) return true;

        // Calculate next cell
        int nextRow = row, nextCol = col + 1;
        if (nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        // Skip already filled cells
        if (board[row][col] != '.') {
            return solver(board, nextRow, nextCol);
        }

        // Try placing digits 1–9
        for (char dig = '1'; dig <= '9'; dig++) {
            if (isSafe(board, row, col, dig)) {
                board[row][col] = dig;               // place digit
                if (solver(board, nextRow, nextCol)) // recurse
                    return true;
                board[row][col] = '.';               // 🔙 backtrack
            }
        }
        return false; // no solution from this path
    }

    // 🚀 Entry point
    void solveSudoku(vector<vector<char>>& board) {
        solver(board, 0, 0);
    }
};
