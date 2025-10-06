/*
🔹 Problem: Maximum XOR of Two Numbers in an Array
-------------------------------------------------
Given an integer array `nums`, return the maximum result of `nums[i] XOR nums[j]` 
where `0 <= i <= j < n`.

✅ Example:
Input: nums = [3, 10, 5, 25, 2, 8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.

✅ Constraints:
- 1 <= nums.length <= 2 * 10^5
- 0 <= nums[i] <= 2^31 - 1
*/


/* 
==================================================================
 Approach: Trie (Bit Manipulation)
==================================================================

🔎 Intuition:
- The idea is to maximize the XOR value by trying to pick the opposite bit 
  at every position (starting from the MSB → LSB).
- We build a **bitwise Trie (prefix tree)** from all numbers:
    - Each node has two children: 0 and 1.
    - Insert numbers bit-by-bit (from bit 31 to 0).
- Then for each number, we traverse the Trie and **greedily** try to go 
  to the opposite bit to maximize the XOR result.

🧠 Why Trie?
- Checking all pairs is O(n^2), which is too slow.
- Trie lets us find the best match for each number in O(32) = O(1) time.

✅ Complexity:
- Time: O(32 * n) ≈ O(n)   → 32 for 32 bits per number
- Space: O(32 * n)         → Trie stores each bit of all numbers
*/

#include <bits/stdc++.h>
using namespace std;

// ----------------------------
// 🔧 Trie Node Definition
// ----------------------------
struct TrieNode {
    TrieNode* next[2] = {nullptr, nullptr};

    bool has(int bit) {
        return next[bit] != nullptr;
    }
    TrieNode* get(int bit) {
        return next[bit];
    }
    void set(int bit, TrieNode* node) {
        next[bit] = node;
    }
};

// ----------------------------
// 🔧 Trie Class Implementation
// ----------------------------
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a number into the Trie
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {   // Traverse from MSB to LSB
            int bit = (num >> i) & 1;
            if (!node->has(bit)) {
                node->set(bit, new TrieNode());
            }
            node = node->get(bit);
        }
    }

    // Compute max XOR for a given number
    int maxXor(int num) {
        TrieNode* node = root;
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            // Try to go to the opposite bit if possible
            if (node->has(1 - bit)) {
                res |= (1 << i);  // Add this bit to result
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return res;
    }
};

// ----------------------------
// ✅ Main Solution Class
// ----------------------------
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        // Step 1: Build Trie with all numbers
        for (int num : nums) trie.insert(num);

        // Step 2: For each number, find the max XOR
        int res = 0;
        for (int num : nums) {
            res = max(res, trie.maxXor(num));
        }
        return res;
    }
};
