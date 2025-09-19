/*
Problem: Find Minimum in Rotated Sorted Array (LeetCode #153)
-------------------------------------------------------------
Suppose an array of length n sorted in ascending order is rotated 
between 1 and n times. Given the rotated array nums, return the 
minimum element.

Example:
--------
Input: nums = [3,4,5,1,2]
Output: 1

Input: nums = [4,5,6,7,0,1,2]
Output: 0

Input: nums = [11,13,15,17]
Output: 11

Constraints:
------------
- n == nums.length
- 1 <= n <= 5000
- -5000 <= nums[i] <= 5000
- All elements are unique
- nums is rotated at least once
*/


// -----------------------------------------------------------------------------
// Approach 0: Linear Scan
// -----------------------------------------------------------------------------
// Idea:
// - Just iterate through the array and keep track of the minimum.
// - O(n) time, O(1) space.
//
class Solution {
public:
    int findMin(vector<int>& nums) {
        int mn = nums[0];
        for (int x : nums) {
            mn = min(mn, x);
        }
        return mn;
    }
};


// -----------------------------------------------------------------------------
// Approach 1: Binary Search (Optimal)
// -----------------------------------------------------------------------------
// Idea:
// - In a rotated sorted array, one half is always sorted.
// - Compare nums[mid] with nums[right]:
//    * If nums[mid] < nums[right] → minimum lies in [left, mid].
//    * Else → minimum lies in [mid+1, right].
// - Keep shrinking range until left == right.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)
//
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) {
                right = mid;     // minimum is in left half (including mid)
            } else {
                left = mid + 1;  // minimum is in right half
            }
        }
        return nums[left]; // or nums[right], both are same here
    }
};
