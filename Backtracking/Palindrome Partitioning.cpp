/*
Problem: Palindrome Partitioning (LeetCode #131)
------------------------------------------------
Given a string `s`, partition `s` such that every substring of the partition 
is a palindrome. Return all possible palindrome partitioning of `s`.

Example:
--------
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Constraints:
------------
- 1 <= s.length <= 16
- s consists of only lowercase English letters.
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Backtracking
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Try all possible partitions of the string.
// - At each step, choose a prefix substring and check if it's a palindrome.
// - If it is, include it in the current partition and recurse on the remainder.
// - When the string is exhausted, add the current partition to the result.
//
// 📌 Example Flow (s = "aab"):
// - "a" | "a" | "b" ✅
// - "aa" | "b" ✅
//
// ⏱️ Time Complexity: O(2^n * n)   (because each character can either cut or not)
// 📦 Space Complexity: O(n)        (recursion + current partition storage)
// -----------------------------------------------------------------------------
class Solution {
public:
    // ✅ Helper: check if a string is palindrome
    bool isPalin(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }

    // 🔁 Backtracking to generate all palindrome partitions
    void getAllParts(string s, vector<string>& partitions, vector<vector<string>>& ans) {
        // ✅ Base case: if string is empty, store current partition
        if (s.size() == 0) {
            ans.push_back(partitions);
            return;
        }

        // ✂️ Try all possible prefixes
        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);

            // ✅ If prefix is palindrome, choose it
            if (isPalin(part)) {
                partitions.push_back(part);
                getAllParts(s.substr(i + 1), partitions, ans); // recurse for remainder
                partitions.pop_back(); // 🔙 backtrack
            }
        }
    }

    // 🚀 Main function
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        getAllParts(s, partitions, ans);
        return ans;
    }
};
