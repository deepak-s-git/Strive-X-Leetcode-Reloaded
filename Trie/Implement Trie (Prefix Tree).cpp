/*
Problem: Implement Trie (Prefix Tree) (LeetCode #208)
-----------------------------------------------------
A **trie** (pronounced as "try") or **prefix tree** is a tree data structure used for 
efficient retrieval of a key in a dataset of strings. 

Implement the `Trie` class:

- `Trie()` Initializes the trie object.
- `void insert(String word)` Inserts the string `word` into the trie.
- `boolean search(String word)` Returns `true` if the string `word` is in the trie 
  (i.e., was inserted before), and `false` otherwise.
- `boolean startsWith(String prefix)` Returns `true` if there is a previously inserted 
  string `word` that starts with the given prefix, and `false` otherwise.

Example:
--------
Input:
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return true
trie.search("app");     // return false
trie.startsWith("app"); // return true
trie.insert("app");
trie.search("app");     // return true

Constraints:
------------
- 1 <= word.length, prefix.length <= 2000
- word and prefix consist of lowercase English letters.
- At most 3 * 10^4 calls will be made to `insert`, `search`, and `startsWith`.
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Trie (Prefix Tree) Implementation
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - A trie is a tree-like data structure where each node represents a character.
// - Traversing from root to a node represents a prefix of some word.
// - `insert`: Traverse character by character and create nodes if not present.
// - `search`: Traverse the trie; if the path exists and `isEnd = true`, the word exists.
// - `startsWith`: Same as search but doesn’t require `isEnd = true`.
//
// 📊 Complexity:
// - ⏱️ Time Complexity: O(L) for insert/search/startsWith (L = length of word/prefix)
// - 📦 Space Complexity: O(N * 26) (N = total characters inserted, 26 children per node)
// -----------------------------------------------------------------------------

// Trie Node Definition
class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    
    TrieNode() {
        isEnd = false;
        for (auto &ch : children) ch = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    // Constructor: Initialize root node
    Trie() {
        root = new TrieNode();
    }
    
    // -------------------------------------------------------------------------
    // ✅ insert(word): Add a word to the Trie
    // -------------------------------------------------------------------------
    void insert(string word) {
        TrieNode* node = root;
        for (auto &ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) 
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true; // Mark the end of the word
    }
    
    // -------------------------------------------------------------------------
    // ✅ search(word): Return true if word exists in Trie
    // -------------------------------------------------------------------------
    bool search(string word, bool isPrefix = false) {
        TrieNode* node = root;
        for (auto &ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) 
                return false; // Path breaks ⇒ word/prefix not present
            node = node->children[idx];
        }
        if (!isPrefix) return node->isEnd; // Must end at a valid word
        return true; // If prefix mode → return true if path exists
    }
    
    // -------------------------------------------------------------------------
    // ✅ startsWith(prefix): Return true if any word starts with given prefix
    // -------------------------------------------------------------------------
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};
