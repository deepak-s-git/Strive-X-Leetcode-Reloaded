/*
Problem: Missing Number (LeetCode #268)
---------------------------------------
Given an array `nums` containing `n` distinct numbers taken 
from the range [0, n], return the only number in the range 
that is missing from the array.

Example 1:
----------
Input:  nums = [3,0,1]
Output: 2

Example 2:
----------
Input:  nums = [0,1]
Output: 2

Example 3:
----------
Input:  nums = [9,6,4,2,3,5,7,0,1]
Output: 8

Constraints:
------------
- n == nums.length
- 1 <= n <= 10^4
- 0 <= nums[i] <= n
- All numbers are unique
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Mathematical Formula (Optimal & Clean)
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Sum of first n natural numbers = n*(n+1)/2
// - Subtract all array elements from expected sum
// - Remaining value is the missing number
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(1)
// -----------------------------------------------------------------------------
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n * (n + 1)) / 2;
        
        for(int i = 0; i < n; i++){
            sum -= nums[i];
        }
        return sum;
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 2: Sorting + Index Check
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Sort the array
// - If nums[i] != i → i is missing
// - If all matched → missing number is n
//
// ⏱ Time Complexity: O(n log n)
// 📦 Space Complexity: O(1)
// -----------------------------------------------------------------------------
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            if(nums[i] != i)
                return i;
        }
        return n;
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 3: XOR Trick (Best Interview Trick)
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - XOR all indices and all numbers
// - Equal numbers cancel out (a ^ a = 0)
// - Remaining value is missing number
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(1)
// -----------------------------------------------------------------------------
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();

        for(int i = 0; i < nums.size(); i++){
            ans ^= i;
            ans ^= nums[i];
        }
        return ans;
    }
};