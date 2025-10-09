/*
🔎 Problem: Counting Bits (LeetCode 338)

Given an integer `n`, return an array `ans` of length `n + 1` such that:
- `ans[i]` is the number of `1` bits (set bits) in the binary representation of `i`
- for every `i` in the range [0, n].

📥 Example:
Input: n = 5
Output: [0, 1, 1, 2, 1, 2]
Explanation:
0 -> 0 (0 bits)
1 -> 1 (1 bit)
2 -> 10 (1 bit)
3 -> 11 (2 bits)
4 -> 100 (1 bit)
5 -> 101 (2 bits)

⚙️ Constraints:
- 0 <= n <= 10^5
*/


/* ================================================================
   ✅ Approach 1: Using Last Bit 
   ================================================================
   🔍 Intuition:
   - The number of 1 bits in `i` can be derived from `i/2`:
     - `i >> 1` shifts `i` right by 1 bit (equivalent to dividing by 2)
     - `(i & 1)` checks if the least significant bit is 1
   - Therefore:
     bitCount[i] = bitCount[i >> 1] + (i & 1)

   🧠 Steps:
   1. Initialize a vector `bitCount` of size `n + 1`.
   2. Loop from 1 to `n`:
      - Compute bits of `i` using previously computed result for `i >> 1`.
   3. Return the result vector.

   📊 Example:
   i = 5 (101)
   - i >> 1 = 2 (10)  -> bitCount[2] = 1
   - (i & 1) = 1       -> last bit is 1
   - bitCount[5] = 1 + 1 = 2

   ⏱️ Complexity:
   - Time:  O(n)
   - Space: O(n)
================================================================ */

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bitCount(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            // bits in i = bits in i/2 + last bit
            bitCount[i] = bitCount[i >> 1] + (i & 1);
        }

        return bitCount;
    }
};
