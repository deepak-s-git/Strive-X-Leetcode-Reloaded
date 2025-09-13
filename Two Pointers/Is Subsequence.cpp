/*
Problem: Is Subsequence (LeetCode #392)
----------------------------------------
Given two strings s and t, return true if s is a subsequence of t, 
or false otherwise.

Examples:
----------
Input: s = "abc", t = "ahbgdc"
Output: true

Input: s = "axc", t = "ahbgdc"
Output: false

Constraints:
-------------
- 0 <= s.length <= 100
- 0 <= t.length <= 10^4
- Both strings consist only of lowercase English letters.
*/


// -----------------------------------------------------------------------------
// Approach 1: Recursive Solution
// -----------------------------------------------------------------------------
/*
Idea:
- Compare characters from the end.
- If last chars match → move both pointers.
- Else → move pointer in t only.
- Base cases:
    - If s is exhausted → true.
    - If t is exhausted first → false.

Time Complexity: O(m * n) in worst case (due to recursion stack).
Space Complexity: O(m + n) recursion depth.
*/

class Solution {
public:
    bool isSubSeq(string str1, string str2, int m, int n) {
        if (m == 0) return true;   // s fully matched
        if (n == 0) return false;  // t exhausted first

        if (str1[m-1] == str2[n-1])
            return isSubSeq(str1, str2, m-1, n-1);

        return isSubSeq(str1, str2, m, n-1);
    }

    bool isSubsequence(string s, string t) {
        return isSubSeq(s, t, s.size(), t.size()); 
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Iterative Two-Pointer Solution
// -----------------------------------------------------------------------------
/*
Idea:
- Use two pointers i (for s) and j (for t).
- If s[i] == t[j], move i forward.
- Always move j forward.
- If i reaches end of s → subsequence found.

Time Complexity: O(n) (single scan of t)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        int i = 0, j = 0;

        while (i < m && j < n) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == m;
    }
};
