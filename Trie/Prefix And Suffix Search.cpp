/*
🔹 Problem: Prefix and Suffix Search (LeetCode #745)
----------------------------------------------------
Design a special data structure `WordFilter` that supports two operations:

- WordFilter(vector<string>& words): Constructor — initializes the object with the given words.
- int f(string prefix, string suffix): Returns the index of the word in `words` which has the given prefix and suffix. 
  If there are multiple valid answers, return the one with the largest index. If no such word exists, return -1.

✅ Example:
Input:
WordFilter wf = WordFilter(["apple"]);
wf.f("a", "e");  // Output: 0

Explanation:
The word "apple" starts with "a" and ends with "e", and its index is 0.

----------------------------------------------------
✅ Constraints:
- 1 <= words.length <= 10^4
- 1 <= words[i].length <= 10
- 1 <= prefix.length, suffix.length <= 10
- All words[i], prefix, suffix consist of lowercase English letters.
*/


/*
==================================================================
 Approach: Trie with Combined Prefix-Suffix Encoding
==================================================================

🔎 Intuition:
We want to efficiently answer queries of the form:
   - Word starts with prefix `p`
   - Word ends with suffix `s`
   - Return the largest index if multiple matches exist.

Naive solution: Iterate over all words and check prefix & suffix → ❌ O(N * L)

We can solve this by **pre-building a Trie** where each path represents a 
**suffix + '{' + prefix** combination for every word.

How?
- For each word `w`, we insert all strings of the form:
  `w[j:] + "{" + w`
  where `w[j:]` is the suffix starting at index `j`
- `'{'` is used as a separator (since it's ASCII after 'z')

🔍 Example:
For word = "apple", we insert into Trie:
- "apple{apple"
- "pple{apple"
- "ple{apple"
- "le{apple"
- "e{apple"

This allows us to directly query:
   suffix + "{" + prefix

✅ Complexity:
- Preprocessing: O(N * L²) → for inserting all combinations
- Query: O(P + S) → length of prefix + suffix
- Space: O(N * L²) → Trie stores all suffix-prefix combinations
*/

#include <bits/stdc++.h>
using namespace std;

class WordFilter {
    // ----------------------------------------
    // 📦 Trie Node Definition
    // ----------------------------------------
    struct Node {
        Node* next[27]; // 26 for 'a'-'z' + 1 for '{'
        int id;         // Store max index of word passing through this node
        Node() : id(-1) {
            for (int i = 0; i < 27; i++) next[i] = nullptr;
        }
    };

    Node* root;

public:
    // ----------------------------------------
    // 🏗️ Constructor: Build Trie with suffix+prefix combinations
    // ----------------------------------------
    WordFilter(vector<string>& words) {
        root = new Node();
        for (int i = 0; i < (int)words.size(); i++) {
            string s = words[i];
            string combo = s + "{" + s; // full suffix + prefix combination

            // Insert every suffix + '{' + word into the Trie
            for (int j = 0; j <= s.size(); j++) {
                ins(combo.substr(j), i);
            }
        }
    }

    // ----------------------------------------
    // 🔎 Query: Find word index with given prefix & suffix
    // ----------------------------------------
    int f(string prefix, string suffix) {
        string key = suffix + "{" + prefix;
        return find(key);
    }

private:
    // ----------------------------------------
    // 📥 Insert a string into Trie
    // ----------------------------------------
    void ins(string s, int id) {
        Node* cur = root;
        for (char c : s) {
            int k = (c == '{') ? 26 : (c - 'a');
            if (!cur->next[k]) cur->next[k] = new Node();
            cur = cur->next[k];
            // Always store the maximum index encountered along this path
            cur->id = max(cur->id, id);
        }
    }

    // ----------------------------------------
    // 🔍 Find the index for a query string
    // ----------------------------------------
    int find(string s) {
        Node* cur = root;
        for (char c : s) {
            int k = (c == '{') ? 26 : (c - 'a');
            if (!cur->next[k]) return -1;
            cur = cur->next[k];
        }
        return cur->id;
    }
};
