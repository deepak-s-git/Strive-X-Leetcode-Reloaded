/*
Problem: Search in Rotated Sorted Array (LeetCode #33)
------------------------------------------------------
There is an integer array nums sorted in ascending order (with distinct values).
The array is rotated at an unknown pivot index k (0 <= k < nums.length).

Given the array nums and an integer target, return the index of target 
if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example:
--------
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Constraints:
------------
- 1 <= nums.length <= 5000
- -10^4 <= nums[i] <= 10^4
- All values are distinct
- nums is rotated at some pivot
*/


// -----------------------------------------------------------------------------
// Approach: Modified Binary Search
// -----------------------------------------------------------------------------
// Idea:
// - Perform binary search, but account for rotation.
// - At each step, check if the left half [left..mid] is sorted.
//   - If target lies within that half, move search space left.
//   - Otherwise, search in the right half.
// - If right half [mid..right] is sorted, do the opposite.
// - Continue until found or search space exhausted.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)
//
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target <= nums[mid]) {
                    right = mid - 1; // search in left half
                } else {
                    left = mid + 1;  // search in right half
                }
            } 
            // Right half is sorted
            else {
                if (nums[mid] <= target && target <= nums[right]) {
                    left = mid + 1;  // search in right half
                } else {
                    right = mid - 1; // search in left half
                }
            }
        }
        return -1;
    }
};
