/*
Problem: Reorganize String (LeetCode #767)
-------------------------------------------
Given a string `s`, rearrange the characters of `s` so that no two adjacent characters 
are the same. Return *any possible* rearrangement or an empty string if not possible.

Example:
--------
Input:  s = "aab"  
Output: "aba"

Input:  s = "aaab"  
Output: ""      (Not possible because 'a' occurs too many times)

Constraints:
------------
- 1 <= s.length <= 500
- s consists of lowercase English letters.
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Max-Heap (Greedy Character Placement)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Always place the two most frequent characters alternately to avoid adjacent duplicates.
// - Use a max-heap to always pick the characters with highest remaining frequency.
// - If at the end one character remains with count > 1 → impossible.
//
// ⏱️ Time Complexity: O(N log 26) ≈ O(N) — inserting and popping from heap
// 📦 Space Complexity: O(26) ≈ O(1) — frequency map and heap
// -----------------------------------------------------------------------------
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char ch : s) freq[ch]++;

        priority_queue<pair<int, char>> pq; // max-heap of {count, character}
        for (auto &[ch, cnt] : freq) pq.push({cnt, ch});

        string ans;
        while (pq.size() > 1) {
            auto [c1, ch1] = pq.top(); pq.pop();
            auto [c2, ch2] = pq.top(); pq.pop();

            ans += ch1;
            ans += ch2;

            if (--c1 > 0) pq.push({c1, ch1});
            if (--c2 > 0) pq.push({c2, ch2});
        }

        // Handle last remaining char
        if (!pq.empty()) {
            auto [cnt, ch] = pq.top();
            if (cnt > 1) return "";  // impossible to reorganize
            ans += ch;
        }

        return ans;
    }
};
