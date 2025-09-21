/*
Problem: Minimum Number of K Consecutive Bit Flips (LeetCode #995)
------------------------------------------------------------------
You are given a binary array nums and an integer k.

A flip operation flips k consecutive bits in the array (0 → 1, 1 → 0).
Return the minimum number of flips required to make the array all 1s.
If it’s not possible, return -1.

Examples:
---------
Input: nums = [0,1,0], k = 1
Output: 2

Input: nums = [1,1,0], k = 2
Output: -1

Input: nums = [0,0,0,1,0,1,1,0], k = 3
Output: 3

Constraints:
------------
- 1 <= nums.length <= 10^5
- 1 <= k <= nums.length
*/


// -----------------------------------------------------------------------------
// Approach: Sliding Window + Lazy Propagation
// -----------------------------------------------------------------------------
// Idea:
// - Instead of actually flipping k elements each time (O(n*k)), 
//   track whether a position has been flipped using an auxiliary array.
// - Maintain a `flipped` state to represent how many flips affect current index.
// - At index i:
//     1. If i >= k, remove the effect of flips that ended before i.
//     2. If nums[i] == flipped, it means current bit is 0 → must flip.
//     3. If flipping exceeds array bounds, return -1.
//     4. Otherwise, record the flip in `isFlipped[i]`, update flipped, and increment result.
// - Continue until end of array.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
//
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flipped = 0;               // current flip state (0/1)
        int res = 0;                   // number of flips performed
        vector<int> isFlipped(n, 0);   // marks if flip starts at index

        for (int i = 0; i < n; i++) {
            // Remove effect of flip that ends here
            if (i >= k) {
                flipped ^= isFlipped[i - k];
            }

            // If current bit (after flips) is 0 → flip
            if (flipped == nums[i]) {
                if (i + k > n) {
                    return -1; // not enough room to flip
                }
                isFlipped[i] = 1;
                flipped ^= 1;
                res++;
            }
        }
        return res;
    }
};
