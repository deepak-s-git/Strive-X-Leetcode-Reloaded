/*
Problem: Binary Search (LeetCode #704)
--------------------------------------
Given an array of integers nums which is sorted in ascending order, 
and an integer target, write a function to search target in nums. 
If target exists, return its index. Otherwise, return -1.

Examples:
---------
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1

Constraints:
------------
- 1 <= nums.length <= 10^4
- -10^4 < nums[i], target < 10^4
- nums is sorted in ascending order
*/

// -----------------------------------------------------------------------------
// Approach : Binary Search (Optimal, O(log n))
// -----------------------------------------------------------------------------
/*
Idea:
- Since nums is sorted, we can use binary search:
  - Check middle element.
  - If nums[mid] == target, return mid.
  - If nums[mid] < target, search right half.
  - Else, search left half.
- Continue until st > end.

Time Complexity: O(log n)
Space Complexity: O(1)
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};
