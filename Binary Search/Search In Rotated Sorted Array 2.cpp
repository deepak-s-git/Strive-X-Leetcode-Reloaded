/*
Problem: Search in Rotated Sorted Array II (LeetCode #81)
---------------------------------------------------------
There is an integer array nums sorted in ascending order (with possible duplicates).
The array is rotated at an unknown pivot index k (0 <= k < nums.length).

Given nums and an integer target, return true if target is in nums, 
or false if it is not in nums.

You must decrease the overall runtime complexity as much as possible.

Example:
--------
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

Constraints:
------------
- 1 <= nums.length <= 5000
- -10^4 <= nums[i] <= 10^4
- nums is rotated at some pivot
*/


// -----------------------------------------------------------------------------
// Approach: Modified Binary Search with Duplicates
// -----------------------------------------------------------------------------
// Idea:
// - Similar to the rotated sorted array search, but handle duplicates.
// - At each step, check if nums[mid] == target.
// - If nums[left] == nums[mid], increment left to skip duplicates.
// - Otherwise, determine which half [left..mid] or [mid..right] is sorted.
//   - If target lies in the sorted half, adjust search space accordingly.
//   - Else, search in the other half.
// - Continue until found or search space exhausted.
//
// Time Complexity: O(log n) in average case, but O(n) in worst case 
//   (when duplicates force linear scan).
// Space Complexity: O(1)
//
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // Skip duplicates
            if (nums[left] == nums[mid]) {
                left++;
                continue;
            }

            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target <= nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } 
            // Right half is sorted
            else {
                if (nums[mid] <= target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
