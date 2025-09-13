/*
Problem: Backspace String Compare (LeetCode #844)
--------------------------------------------------
Given two strings s and t, return true if they are equal when both
are typed into empty text editors. '#' means a backspace character.

Examples:
----------
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both become "ac".

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both become "".

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".

Constraints:
-------------
- 1 <= s.length, t.length <= 200
- s and t only contain lowercase letters and '#' characters.
*/


// -----------------------------------------------------------------------------
// Approach 1: In-place Processing with Index
// -----------------------------------------------------------------------------
/*
Idea:
- Treat string as a char array.
- Use index k to simulate writing valid chars.
- If '#' encountered, reduce index if possible (backspace).
- Compare processed results.

Time Complexity: O(n + m)  
Space Complexity: O(1) (in-place processing)
*/

class Solution {
public:
    int processStr(string& str) {
        int k = 0;
        for (char c : str) {
            if (c != '#') {
                str[k++] = c;
            } else if (k > 0) {
                k--; // backspace
            }
        }
        return k;
    }

    bool backspaceCompare(string s, string t) {
        int k = processStr(s);
        int p = processStr(t);

        if (k != p) return false;

        for (int i = 0; i < k; i++) {
            if (s[i] != t[i]) return false;
        }
        return true;
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Stack-like Processing with Extra String
// -----------------------------------------------------------------------------
/*
Idea:
- Use an auxiliary string to simulate a stack.
- Push characters if not '#'.
- Pop from stack when '#' encountered.
- Compare final processed strings.

Time Complexity: O(n + m)  
Space Complexity: O(n + m) (extra storage)
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return processStr(s) == processStr(t);        
    }

    string processStr(string str) {
        string res;
        for (char c : str) {
            if (c != '#') {
                res.push_back(c);
            } else if (!res.empty()) {
                res.pop_back();
            }
        }
        return res;
    }
};
