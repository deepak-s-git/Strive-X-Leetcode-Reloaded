/*
💠 Problem: Palindromic Substrings (LeetCode 647)

Given a string `s`, return the number of **palindromic substrings** in it.  
A string is a palindrome when it reads the same forward and backward.

📥 Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic substrings: "a", "b", "c"

📥 Example 2:
Input: s = "aaa"
Output: 6
Explanation: "a", "a", "a", "aa", "aa", "aaa"

⚙️ Constraints:
- 1 <= s.length <= 1000
- s consists of lowercase English letters only.
*/


/* ================================================================
   ✅ Approach 1: Dynamic Programming (Bottom-Up)
   ================================================================
   🔍 Intuition:
   - We maintain a 2D DP table `pal[i][j]` that indicates whether
     substring `s[i..j]` is a palindrome.
   - Base Cases:
       - Single char → always palindrome
       - Two chars → palindrome if both same
   - For longer substrings, `s[i..j]` is palindrome if:
       s[i] == s[j] && pal[i+1][j-1] == true

   ⏱️ Complexity:
   - Time:  O(n²)
   - Space: O(n²)
================================================================ */

class Solution {
public:
    int countSubstrings(string str) {
        int len = str.size();
        vector<vector<bool>> pal(len, vector<bool>(len, false));
        int res = 0;

        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (i == j) pal[i][j] = true;
                else if (j == i + 1) pal[i][j] = (str[i] == str[j]);
                else pal[i][j] = (str[i] == str[j]) && pal[i + 1][j - 1];
                if (pal[i][j]) res++;
            }
        }
        return res;
    }
};


/* ================================================================
   ✅ Approach 2: Expand Around Center
   ================================================================
   🔍 Intuition:
   - Every palindrome has a center.
   - Expand around each possible center (single char or pair)
     and count all valid palindromes.

   ⏱️ Complexity:
   - Time:  O(n²)
   - Space: O(1)
================================================================ */

class Solution {
private:
    int total = 0;
public:
    int countSubstrings(string text) {
        if (text.empty()) return 0;
        for (int k = 0; k < text.size(); k++) {
            expand(text, k, k);     // Odd-length palindrome
            expand(text, k, k + 1); // Even-length palindrome
        }
        return total;
    }
private:
    void expand(string& text, int l, int r) {
        while (l >= 0 && r < text.size() && text[l] == text[r]) {
            total++;
            l--;
            r++;
        }
    }
};


/* ================================================================
   ✅ Approach 3: Manacher’s Algorithm (Optimized O(n))
   ================================================================
   🔍 Intuition:
   - Transform string using separators (`#`) to handle both even
     and odd length palindromes uniformly.
   - Use previously computed palindrome lengths to minimize expansion.

   ⏱️ Complexity:
   - Time:  O(n)
   - Space: O(n)
================================================================ */

class Solution {
public:
    int countSubstrings(string word) {
        int n = word.size();
        string mod = "#";
        for (char ch : word) {
            mod += ch;
            mod += "#";
        }

        n = mod.size();
        vector<int> radius(n, 0);
        int mid = 0, bound = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            int mirror = 2 * mid - i;
            if (i < bound)
                radius[i] = min(bound - i, radius[mirror]);

            int x = i + 1 + radius[i];
            int y = i - 1 - radius[i];
            while (x < n && y >= 0 && mod[x] == mod[y]) {
                radius[i]++;
                x++;
                y--;
            }

            if (i + radius[i] > bound) {
                mid = i;
                bound = i + radius[i];
            }

            ans += (radius[i] + 1) / 2;
        }

        return ans;
    }
};
