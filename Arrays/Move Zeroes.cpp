/*
Problem: Move Zeroes (LeetCode #283)
-------------------------------------
Given an integer array `nums`, move all 0's to the end of it
while maintaining the relative order of the non-zero elements.

You must do this in-place if possible.

Example:
--------
Input:  nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Input:  nums = [0]
Output: [0]

Constraints:
------------
- 1 <= nums.length <= 10^4
- -2^31 <= nums[i] <= 2^31 - 1
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Extra Array (Brute Force)
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Traverse array
// - Push all non-zero elements into a new vector
// - Count zeros
// - Append zeros at end
// - Copy back
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(n)
// -----------------------------------------------------------------------------
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int c = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                ans.push_back(nums[i]);
            } else {
                c++;
            }
        }

        for(int i = 0; i < c; i++){
            ans.push_back(0);
        }

        nums = ans;
    }
};




// -----------------------------------------------------------------------------
// ✅ Approach 2: Two-Pointer (Overwrite Method)
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Use pointer j to track position for next non-zero
// - First pass: place all non-zero elements at front
// - Second pass: fill remaining positions with zero
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(1)
// -----------------------------------------------------------------------------
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                nums[j] = nums[i];
                j++;
            }
        }

        for(int i = j; i < n; i++){
            nums[i] = 0;
        }
    }
};



// -----------------------------------------------------------------------------
// ✅ Approach 3: Two-Pointer (Optimal Swap Method)
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Maintain pointer j for next non-zero position
// - When non-zero found → swap with nums[j]
// - Ensures in-place and minimal operations
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(1)
// -----------------------------------------------------------------------------
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};