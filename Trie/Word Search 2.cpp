/*
🔹 Problem: Word Search II (LeetCode #212)
-----------------------------------------
Given an m x n board of characters and a list of strings `words`, return all words 
on the board that can be formed by sequentially adjacent letters.

- Letters must be adjacent horizontally or vertically.
- The same letter cell may not be used more than once in a word.

✅ Example:
Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]

✅ Constraints:
- 1 <= board.length, board[0].length <= 12
- 1 <= words.length <= 3 * 10^4
- 1 <= words[i].length <= 10
*/


/*
==================================================================
 Approach: Trie + DFS Backtracking
==================================================================

🔎 Intuition:
- Brute-force would try each word in every position → O(N * M * 4^L) → Too slow.
- Instead, we **build a Trie** of all words for efficient prefix checking.
- Then, we **DFS** from each cell:
  - Explore adjacent cells (up/down/left/right).
  - If current path is not a prefix in Trie → prune immediately.
  - If we reach a word in Trie → add it to the result and mark it as found.

⚡ Optimization:
- Clear the word (`node->word.clear()`) after adding it to results → avoids duplicates.
- Use `'#'` to mark visited cells temporarily (no extra space for visited[][]).

✅ Complexity:
- Time: O(M * N * 4^L) worst-case, but with Trie pruning it’s much faster in practice.
- Space: O(K * L) for Trie, where K = number of words, L = max length of a word.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    // ----------------------------
    // 📦 Trie Node Structure
    // ----------------------------
    struct TrieNode {
        TrieNode* next[26];
        string word;  // stores a word when a complete word ends here
        TrieNode() : word("") {
            for (int i = 0; i < 26; i++) next[i] = nullptr;
        }
    };

public:
    // ----------------------------
    // 🚀 Main Function
    // ----------------------------
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);   // Build Trie of all words
        vector<string> found;

        int rows = board.size();
        int cols = board[0].size();

        // Try starting DFS from every cell
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, root, found);
            }
        }
        return found;
    }

private:
    // ----------------------------
    // 🏗️ Build Trie from Words
    // ----------------------------
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& w : words) {
            TrieNode* node = root;
            for (char ch : w) {
                int idx = ch - 'a';
                if (!node->next[idx]) node->next[idx] = new TrieNode();
                node = node->next[idx];
            }
            node->word = w;  // mark the end of a word
        }
        return root;
    }

    // ----------------------------
    // 🔎 DFS Backtracking Search
    // ----------------------------
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& found) {
        char ch = board[r][c];
        if (ch == '#' || !node->next[ch - 'a']) return;  // invalid path or visited

        node = node->next[ch - 'a'];

        // ✅ Found a complete word
        if (!node->word.empty()) {
            found.push_back(node->word);
            node->word.clear(); // avoid duplicates
        }

        // mark visited
        board[r][c] = '#';

        // explore 4 directions
        if (r > 0) dfs(board, r - 1, c, node, found);
        if (c > 0) dfs(board, r, c - 1, node, found);
        if (r < board.size() - 1) dfs(board, r + 1, c, node, found);
        if (c < board[0].size() - 1) dfs(board, r, c + 1, node, found);

        // unmark visited
        board[r][c] = ch;
    }
};
