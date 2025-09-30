/*
Problem: Split a String Into the Max Number of Unique Substrings (LeetCode #1593)
---------------------------------------------------------------------------------
Given a string `s`, split it into the maximum number of **unique substrings**.

- A substring is any non-empty contiguous sequence of characters within a string.
- The split must cover the entire string.
- The goal is to maximize the number of *unique* substrings.

Example:
--------
Input: s = "ababccc"
Output: 5
Explanation: One optimal split is ["a","b","ab","c","cc"]

Constraints:
------------
- 1 <= s.length <= 16
- `s` contains only lowercase English letters
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Backtracking + HashSet
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - At every index, try splitting the string into all possible substrings starting
//   from that position.
// - For each substring, if it's not already used, include it and recurse for the
//   remaining string.
// - Track the maximum number of unique substrings formed.
// - Use a `set` to maintain uniqueness during recursion.
//
// 📌 Example Flow: s = "aba"
// - "a" + dfs("ba")
// - "ab" + dfs("a")
// - "aba" + dfs("")
//
// ⏱️ Time Complexity: O(2^n * n)   (exponential due to substring choices)
// 📦 Space Complexity: O(n)        (recursion + set storage)
// -----------------------------------------------------------------------------
class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> used; // ✅ to track used substrings
        return dfs(0, s, used);
    }

private:
    // 🔁 Backtracking helper
    int dfs(int start, const string& s, unordered_set<string>& used) {
        // ✅ Base case: reached the end
        if (start == s.size()) return 0;

        int maxCount = 0;

        // 🔎 Try all possible substrings starting at `start`
        for (int end = start + 1; end <= s.size(); ++end) {
            string part = s.substr(start, end - start);

            // 🧪 Only use if unique
            if (!used.count(part)) {
                used.insert(part); // choose
                maxCount = max(maxCount, 1 + dfs(end, s, used)); // recurse
                used.erase(part); // 🔙 backtrack
            }
        }
        return maxCount;
    }
};
