/*
Problem: Longest Word in Dictionary (LeetCode #720)
----------------------------------------------------
Given an array of strings `words` representing a dictionary, return the longest word in 
the dictionary that can be built one character at a time by other words in `words`.

- If there is more than one possible answer, return the lexicographically smallest one.
- If no word can be built, return "".

Example:
--------
Input:  words = ["w","wo","wor","worl","world"]
Output: "world"

Input:  words = ["a","banana","app","appl","ap","apply","apple"]
Output: "apple"

Constraints:
------------
- 1 <= words.length <= 1000
- 1 <= words[i].length <= 30
- words[i] consists of lowercase English letters only.
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Trie + DFS
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Insert all words into a Trie.
// - A word is only valid if all of its prefixes are also present in the Trie 
//   as complete words.
// - Perform DFS from root, traversing only nodes that represent complete words.
// - Keep track of the longest valid word found; if tie, choose lexicographically smaller.
//
// 📊 Complexity:
// - ⏱️ Time Complexity: O(N * L) where N = number of words, L = max length of a word
// - 📦 Space Complexity: O(N * L) for storing Trie
// -----------------------------------------------------------------------------

class TrieNode {
public:
    TrieNode* children[26];
    bool isWordEnd;
    string word;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isWordEnd = false;
        word = "";
    }
};

class Solution {
private:
    TrieNode* root;

    // Insert word into Trie
    void insertWord(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isWordEnd = true;
        node->word = word;
    }

    // DFS: explore only valid words where each prefix exists
    void dfs(TrieNode* node, string& result) {
        if (node == nullptr || !node->isWordEnd)
            return;

        // Update result if longer or lexicographically smaller
        if (node->word.size() > result.size() ||
            (node->word.size() == result.size() && node->word < result)) {
            result = node->word;
        }

        for (int i = 0; i < 26; i++) {
            if (node->children[i] && node->children[i]->isWordEnd)
                dfs(node->children[i], result);
        }
    }

public:
    Solution() {
        root = new TrieNode();
    }

    string longestWord(vector<string>& words) {
        // Step 1: Insert all words
        for (const string& word : words)
            insertWord(word);

        // Step 2: DFS to find the longest valid word
        string result = "";
        for (int i = 0; i < 26; i++) {
            if (root->children[i])
                dfs(root->children[i], result);
        }

        return result;
    }
};
