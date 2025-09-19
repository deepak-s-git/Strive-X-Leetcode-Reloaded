/*
Problem: Find Smallest Letter Greater Than Target (LeetCode #744)
-----------------------------------------------------------------
You are given an array of characters letters that is sorted in non-decreasing order, 
and a character target. There are at least two different characters in letters.

Return the smallest character in letters that is strictly greater than target.

Note: letters wrap around. For example, if target = 'z' and letters = ['a','b'], 
then the answer is 'a'.

Examples:
---------
Input: letters = ["c","f","j"], target = "a"
Output: "c"

Input: letters = ["c","f","j"], target = "c"
Output: "f"

Input: letters = ["c","f","j"], target = "d"
Output: "f"

Constraints:
------------
- 2 <= letters.length <= 10^4
- letters[i] is a lowercase English letter
- letters is sorted in non-decreasing order
- letters contain at least two different characters
*/


// -----------------------------------------------------------------------------
// Approach 1: Brute Force (O(n))
// -----------------------------------------------------------------------------
/*
Idea:
- Iterate through all letters.
- Return the first one that is greater than target.
- If none found, wrap around and return first letter.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (char alpha : letters) {
            if (alpha > target) {
                return alpha;
            }
        }
        return letters[0]; // wrap around
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Binary Search (O(log n))
// -----------------------------------------------------------------------------
/*
Idea:
- Since letters is sorted, we can binary search for the smallest element > target.
- Standard binary search pattern:
  - If letters[mid] > target, move right boundary (search left side).
  - Else, move left boundary (search right side).
- At the end, left will point to the first element > target.
- Use modulo (left % n) to handle wrap-around.

Time Complexity: O(log n)
Space Complexity: O(1)
*/
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (letters[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return letters[left % letters.size()];
    }
};
