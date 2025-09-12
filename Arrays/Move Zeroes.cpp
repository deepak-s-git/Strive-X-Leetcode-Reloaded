/*
Problem: Move Zeroes (LeetCode #283)
-------------------------------------
Given an integer array nums, move all 0's to the end of it while maintaining 
the relative order of the non-zero elements.

Note: You must do this in-place without making a copy of the array.

Examples:
----------
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Input: nums = [0]
Output: [0]

Constraints:
-------------
- 1 <= nums.length <= 10^4
- -2^31 <= nums[i] <= 2^31 - 1
*/


// -----------------------------------------------------------------------------
// Brute Force Idea (Not Implemented)
// -----------------------------------------------------------------------------
// Create a new array, copy non-zero elements, then append zeros.
// Copy result back into nums.
// Time: O(n), Space: O(n) → not allowed since problem asks in-place.


// -----------------------------------------------------------------------------
// Approach 1: Overwrite Non-Zeros + Fill Zeros
// -----------------------------------------------------------------------------
/*
Idea:
- Iterate through nums, copy non-zero elements forward.
- After all non-zeros are placed, fill the rest with 0.
- Maintains relative order.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // position to place the next non-zero
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }
        // Fill remaining positions with zeros
        for (int i = j; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Two-Pointer Swap
// -----------------------------------------------------------------------------
/*
Idea:
- Use two pointers: i (current index), j (position for next non-zero).
- When nums[i] is non-zero, swap it with nums[j] and increment j.
- Ensures relative order is preserved while moving zeros to the end.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // position for next non-zero
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
