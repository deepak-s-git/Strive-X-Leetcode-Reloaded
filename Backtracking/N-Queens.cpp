/*
Problem: N-Queens (LeetCode #51)
---------------------------------
The N-Queens puzzle is the problem of placing `n` queens on an `n x n` chessboard 
such that no two queens attack each other.

- A queen can attack another queen if they are in the same:
  1. Row
  2. Column
  3. Diagonal

Return all distinct solutions where 'Q' represents a queen and '.' an empty space.

Example:
--------
Input: n = 4
Output: 
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

Constraints:
------------
- 1 <= n <= 9
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Backtracking
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Place queens row by row. For each row, try every column and check if it's safe.
// - A position is safe if:
//   - No queen is placed in the same column.
//   - No queen is placed in the same diagonal.
// - If a position is safe, place a queen and recursively solve for the next row.
// - If all queens are placed → store the current board as a valid solution.
//
// ⚙️ Steps:
// 1. Start with an empty board.
// 2. Try to place a queen in each column of the current row.
// 3. Use `isSafe()` to check if it's valid.
// 4. If valid → place queen and move to the next row.
// 5. If we reach beyond the last row → add the solution to `solutions`.
// 6. Backtrack: remove the queen and try next column.
//
// ⏱️ Time Complexity: O(N!) – since we try all possible placements row by row.
// 📦 Space Complexity: O(N^2) – for the board + recursion stack.
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<vector<string>> solutions; // ✅ Stores all valid board configurations

    // 🔍 Check if it's safe to place a queen at (row, col)
    bool isSafe(const vector<string>& board, int row, int col) {
        // 🔁 Check same column upwards
        for (int i = row; i >= 0; --i) {
            if (board[i][col] == 'Q') return false;
        }

        // ↖️ Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }

        // ↗️ Check upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < board.size(); --i, ++j) {
            if (board[i][j] == 'Q') return false;
        }

        return true; // ✅ Safe to place queen here
    }

    // 🔁 Backtracking function to place queens row by row
    void backtrack(vector<string>& board, int row) {
        // 🏁 Base case: All queens placed successfully
        if (row == board.size()) {
            solutions.push_back(board);
            return;
        }

        // 📍 Try placing a queen in each column of this row
        for (int col = 0; col < board.size(); ++col) {
            if (isSafe(board, row, col)) {          // ✅ Safe spot found
                board[row][col] = 'Q';              // 👑 Place queen
                backtrack(board, row + 1);          // 🔁 Recurse to next row
                board[row][col] = '.';              // ↩️ Backtrack (remove queen)
            }
        }
    }

    // 🚀 Entry point
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.')); // initialize empty board
        backtrack(board, 0);
        return solutions;
    }
};
