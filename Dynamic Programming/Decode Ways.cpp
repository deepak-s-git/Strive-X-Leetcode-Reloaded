/*
🔤 Problem: Decode Ways (LeetCode 91)

A message containing letters from A-Z can be encoded into numbers using the mapping:
'A' -> 1, 'B' -> 2, ..., 'Z' -> 26

Given a string `s` containing only digits, return the **total number of ways** to decode it.

⚠️ Rules:
- '0' cannot be decoded alone.
- Valid two-digit decodings are from "10" to "26".

📥 Example 1:
Input: s = "12"
Output: 2
Explanation: "12" -> "AB" (1 2) or "L" (12)

📥 Example 2:
Input: s = "226"
Output: 3
Explanation: "2 2 6" -> "BBF", "22 6" -> "VF", "2 26" -> "BZ"

📥 Example 3:
Input: s = "06"
Output: 0 (Invalid since message can't start with '0')

⚙️ Constraints:
- 1 <= s.length <= 100
- `s` consists of only digits and may contain leading zeros.
*/

/* ================================================================
   ✅ Approach 1: Dynamic Programming (Bottom-Up)
   ================================================================
   🔍 Intuition:
   - `ways[i]` = number of ways to decode substring `s[0...i-1]`.
   - Base cases:
       ways[0] = 1 (empty string)
       ways[1] = 1 (if s[0] != '0')
   - For each position `i`:
       - If single digit `s[i-1]` is valid (1-9), add `ways[i-1]`.
       - If two digits `s[i-2..i-1]` is valid (10-26), add `ways[i-2]`.

   🧠 Transition Formula:
   ways[i] = (if single valid) ways[i-1] + (if double valid) ways[i-2]

   📊 Dry Run:
   s = "226"
   ways[0] = 1, ways[1] = 1
   i=2: "2" valid → ways[2] += ways[1] (1)
        "22" valid → ways[2] += ways[0] (1)  ✅ ways[2] = 2
   i=3: "6" valid → ways[3] += ways[2] (2)
        "26" valid → ways[3] += ways[1] (1)  ✅ ways[3] = 3

   ⏱️ Complexity:
   - Time:  O(n)
   - Space: O(n)   (can be reduced to O(1))
================================================================ */

class Solution {
public:
    int numDecodings(std::string s) {
        if (s.empty() || s[0] == '0') return 0; // Edge case: can't start with 0

        int n = s.length();
        std::vector<int> ways(n + 1, 0);
        ways[0] = 1; // empty string
        ways[1] = 1; // first char valid (non-zero)

        for (int i = 2; i <= n; ++i) {
            int singleDigit = s[i - 1] - '0';            // Current digit
            int doubleDigit = std::stoi(s.substr(i - 2, 2)); // Last two digits

            if (singleDigit != 0) { 
                ways[i] += ways[i - 1]; // Single digit decode
            }
            if (doubleDigit >= 10 && doubleDigit <= 26) { 
                ways[i] += ways[i - 2]; // Double digit decode
            }
        }

        return ways[n];
    }
};
