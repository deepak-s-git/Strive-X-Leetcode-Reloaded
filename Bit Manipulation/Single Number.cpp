/*
Problem: Single Number (LeetCode #136)
---------------------------------------
Given a non-empty array of integers nums, every element appears twice except for one.
Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Examples:
----------
Input: nums = [2,2,1]
Output: 1

Input: nums = [4,1,2,1,2]
Output: 4

Input: nums = [1]
Output: 1

Constraints:
-------------
- 1 <= nums.length <= 3 * 10^4
- -3 * 10^4 <= nums[i] <= 3 * 10^4
- Each element in the array appears twice except for one element which appears only once.
*/

// -----------------------------------------------------------------------------
// Approach 2: XOR Trick (Optimal)
// -----------------------------------------------------------------------------
/*
Idea:
- XOR of two identical numbers cancels out (a ^ a = 0).
- XOR of a number with 0 is the number itself (a ^ 0 = a).
- So XOR-ing all numbers leaves only the unique one.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int val : nums) {
            ans ^= val;   // cancel out duplicates
        }
        return ans;
    }
};