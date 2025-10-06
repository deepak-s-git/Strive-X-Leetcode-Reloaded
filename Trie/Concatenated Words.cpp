/*
🔹 Problem: Concatenated Words (LeetCode #472)
------------------------------------------------
Given an array of strings `words` (without duplicates), return all the concatenated words 
in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words 
(including possibly repeated words) from the given array.

✅ Example:
Input: 
words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: 
["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation:
- "catsdogcats" is "cats" + "dog" + "cats"
- "dogcatsdog" is "dog" + "cats" + "dog"
- "ratcatdogcat" is "rat" + "cat" + "dog" + "cat"

✅ Constraints:
- 1 <= words.length <= 10^4
- 0 <= words[i].length <= 1000
- words[i] consists of only lowercase English letters.
- All words are unique.
*/


/*
==================================================================
 Approach: Trie + DFS (Word Decomposition)
==================================================================

🔎 Intuition:
- A concatenated word must be formed by combining **two or more words** already present in the list.
- We can use a **Trie** to store all words, and for each new word, check if it can be formed by 
  concatenating smaller words already present in the Trie.
- We process words in increasing order of length:
  - This ensures shorter words are available in the Trie when checking longer ones.
- While checking a word, if we reach a Trie node where `isWord == true`, 
  we recursively try to match the remaining part of the word again from the Trie root.

⚡ Key Details:
- Use DFS with `count` parameter to track how many words we've matched so far.
- Only return true if we reach the end of the word **and** `count >= 1` (means word is formed by ≥2 words).
- Insert a word into the Trie **only after** checking it — avoids matching the word with itself.

✅ Complexity:
- Time: O(N * L²)  (where N = number of words, L = max word length)
  - Sorting: O(N log N)
  - DFS checking for each word: ~O(L²) worst case
- Space: O(N * L) for Trie storage
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // ----------------------------------------
    // 📦 Trie Node Definition
    // ----------------------------------------
    struct TrieNode {
        vector<TrieNode*> children{26, nullptr};
        bool isWord = false;
    };

    TrieNode* root;

    // ----------------------------------------
    // 🏗️ Insert a word into the Trie
    // ----------------------------------------
    void insert(const string& word) {
        if (word.empty()) return;
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isWord = true;
    }

    // ----------------------------------------
    // 🔎 DFS: Check if a word can be formed by concatenating existing words
    // ----------------------------------------
    bool dfs(TrieNode* rootNode, TrieNode* node, const string& word, int pos, int count) {
        if (!node) return false;

        // ✅ Base case: reached end of word
        if (pos == word.size())
            return node->isWord && count >= 1; // formed by ≥ 2 words

        // If current node marks the end of a word, try restarting from root for the next part
        if (node->isWord && dfs(rootNode, rootNode, word, pos, count + 1))
            return true;

        // Continue traversing Trie for next character
        int idx = word[pos] - 'a';
        return dfs(rootNode, node->children[idx], word, pos + 1, count);
    }

public:
    // ----------------------------------------
    // 🚀 Main Function
    // ----------------------------------------
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // Sort words by length → ensures shorter words are processed first
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        root = new TrieNode();
        vector<string> result;

        for (const auto& word : words) {
            if (word.empty()) continue;

            // Check if the word can be formed by concatenating others
            if (dfs(root, root, word, 0, 0)) {
                result.push_back(word);
            } else {
                // Insert into Trie for future words to use
                insert(word);
            }
        }

        return result;
    }
};
