/*
Problem: Word Search (LeetCode #79)
-----------------------------------
Given an `m x n` grid of characters `board` and a string `word`, return `true`
if `word` exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Example:
--------
Input:
board = [
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED"

Output: true

Constraints:
------------
- m == board.length
- n == board[i].length
- 1 <= m, n <= 6
- 1 <= word.length <= 15
- board and word consist of lowercase and uppercase English letters.
*/


// -----------------------------------------------------------------------------
// ✅ Approach: DFS + Backtracking
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// We try to match the word starting from every cell that matches the first character.
// Then, we use DFS to explore in 4 directions (up, down, left, right).
// At each step:
//  - If the current cell doesn't match the word[k], backtrack.
//  - If we matched all characters (k == word.length), return true.
//  - Mark the current cell as visited (e.g., replace with '#') to avoid reuse.
//  - Explore neighbors recursively.
//  - Backtrack by restoring the original character.
//
// ⚡ Why This Works:
// By exploring all possible paths with backtracking and pruning mismatches early,
// we efficiently check if the word exists without revisiting cells.
//
// ⏱️ Time Complexity: O(M * N * 4^L)
//      - M*N: starting points
//      - 4^L: worst case DFS branching factor (L = length of word)
// 📦 Space Complexity: O(L) recursion depth (stack) + O(1) extra space
// -----------------------------------------------------------------------------


class Solution {
private:
    int M, N; // Dimensions of the board

    // DFS helper function to search for the word starting from board[i][j]
    bool dfs(vector<vector<char>>& board, int i, int j, const string& word, int k) {
        // ✅ Base case: all characters matched
        if (k == word.length()) return true;

        // ❌ Out of bounds or character mismatch
        if (i < 0 || i >= M || j < 0 || j >= N || board[i][j] != word[k]) return false;

        // Mark the cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore all 4 directions
        bool found = dfs(board, i + 1, j, word, k + 1) ||  // ↓ Down
                     dfs(board, i - 1, j, word, k + 1) ||  // ↑ Up
                     dfs(board, i, j + 1, word, k + 1) ||  // → Right
                     dfs(board, i, j - 1, word, k + 1);    // ← Left

        // 🔁 Backtrack: restore original character
        board[i][j] = temp;
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;         // empty word always exists
        if (board.empty() || board[0].empty()) return false;

        M = board.size();
        N = board[0].size();

        // 🔍 Try starting DFS from every cell matching first letter
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, i, j, word, 0)) return true;
                }
            }
        }
        return false;
    }
};