/*
Problem: Letter Combinations of a Phone Number (LeetCode #17)
------------------------------------------------------------
Given a string containing digits from 2-9 inclusive, return all possible letter 
combinations that the number could represent. Return the answer in any order.

Each digit maps to a set of letters (like on a phone keypad):

2 -> "abc", 3 -> "def", 4 -> "ghi", 5 -> "jkl"
6 -> "mno", 7 -> "pqrs", 8 -> "tuv", 9 -> "wxyz"

Example:
--------
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Constraints:
------------
- 0 <= digits.length <= 4
- digits[i] is a digit from '2' to '9'
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Backtracking (DFS)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Treat the problem as building all possible strings by choosing one letter
//   for each digit in order.
// - At each index, loop over the possible letters for that digit and recurse.
// - Once we’ve built a string of full length, add it to the result.
//
// 📌 Example Flow (digits = "23"):
// - Choose 'a' → 'd', 'e', 'f'
// - Choose 'b' → 'd', 'e', 'f'
// - Choose 'c' → 'd', 'e', 'f'
//
// ⏱️ Time Complexity: O(4^n)   (worst case, each digit has 4 options)
// 📦 Space Complexity: O(n)    (recursion depth + current string)
// -----------------------------------------------------------------------------
class Solution {
private:
    // 🔁 Backtracking helper to build all possible combinations
    void backtrack(const string& digits, int index, string& current,
                   vector<string>& result, const vector<string>& keypad) {
        // ✅ Base case: if we've formed a full combination
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        // 🔡 Get all possible letters for current digit
        string letters = keypad[digits[index] - '0'];
        for (char ch : letters) {
            current.push_back(ch);                               // choose a letter
            backtrack(digits, index + 1, current, result, keypad); // recurse
            current.pop_back();                                  // 🔙 backtrack
        }
    }

public:
    // 🚀 Main function
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; // edge case

        // 📞 Keypad mapping
        vector<string> keypad = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        string current;
        backtrack(digits, 0, current, result, keypad);
        return result;
    }
};
