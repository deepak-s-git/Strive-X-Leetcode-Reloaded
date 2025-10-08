/*
🔁 Problem: Longest Palindromic Substring (LeetCode 5)

Given a string `s`, return the **longest palindromic substring** in `s`.

A palindrome is a string that reads the same backward as forward.

📥 Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

📥 Example 2:
Input: s = "cbbd"
Output: "bb"

📥 Example 3:
Input: s = "a"
Output: "a"

📥 Example 4:
Input: s = "ac"
Output: "a"

⚙️ Constraints:
- 1 <= s.length <= 1000
- s consists of only digits and English letters.
*/

/* ================================================================
   ✅ Approach 1: Expand Around Center
   ================================================================
   🔍 Intuition:
   - A palindrome mirrors around its center.
   - Each center can be:
       1. A single character (odd-length palindrome)
       2. A pair of characters (even-length palindrome)
   - For each character, try expanding around both types of centers.
   - Keep track of the longest palindrome seen so far.

   🧠 Key Idea:
   - Expand left and right as long as `s[left] == s[right]`.
   - Calculate palindrome length and update the best range if it's longer.

   📊 Dry Run:
   s = "babad"

   - center=0: "b" (len=1)
   - center=1: "bab" (len=3) ✅
   - center=2: "aba" (len=3) ✅
   - center=3: "ad" (len=1)
   - center=4: "d" (len=1)
   -> Result: "bab" or "aba"

   ⏱️ Complexity:
   - Time:  O(n^2)   -> Expand around each center (2n centers)
   - Space: O(1)     -> Only a few variables used
================================================================ */

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int palindromeStart = 0;
        int palindromeEnd = 0;

        for (int center = 0; center < s.length(); center++) {
            // Odd-length palindrome (single character center)
            int lenOdd = expandAroundCenter(s, center, center);
            // Even-length palindrome (two-character center)
            int lenEven = expandAroundCenter(s, center, center + 1);
            
            int maxLen = max(lenOdd, lenEven);

            if (maxLen > palindromeEnd - palindromeStart) {
                palindromeStart = center - (maxLen - 1) / 2;
                palindromeEnd = center + maxLen / 2;
            }
        }

        return s.substr(palindromeStart, palindromeEnd - palindromeStart + 1);
    }

private:
    // Expands from the center and returns the palindrome length
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};
