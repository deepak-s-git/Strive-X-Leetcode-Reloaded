/*
Problem: Missing Number (LeetCode #268)
----------------------------------------
Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array.

Examples:
----------
Input: nums = [3,0,1]
Output: 2

Input: nums = [0,1]
Output: 2

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8

Constraints:
-------------
- n == nums.length
- 1 <= n <= 10^4
- 0 <= nums[i] <= n
- All the numbers of nums are unique
*/

// -----------------------------------------------------------------------------
// Approach : XOR Trick
// -----------------------------------------------------------------------------
/*
Idea:
- XOR all numbers from 0 to n and all numbers in nums.
- The duplicates cancel out, leaving only the missing number.
- Uses the property: x ^ x = 0 and x ^ 0 = x.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            ans ^= i;
            ans ^= nums[i];
        }
        return ans;
    }
};