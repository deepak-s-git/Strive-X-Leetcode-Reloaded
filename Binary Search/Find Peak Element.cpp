/*
Problem: Find Peak Element (LeetCode #162)
------------------------------------------
A peak element is an element that is strictly greater than its neighbors. 
Given an integer array nums, find a peak element, and return its index. 
If the array contains multiple peaks, return the index to any of the peaks.

You may imagine nums[-1] = -∞ and nums[n] = -∞.

Example:
--------
Input: nums = [1,2,3,1]
Output: 2   // because nums[2] = 3 is greater than both neighbors

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5   // both nums[1]=2 and nums[5]=6 are peaks

Constraints:
------------
- 1 <= nums.length <= 1000
- -2^31 <= nums[i] <= 2^31 - 1
- nums[i] != nums[i+1] for all valid i
*/


// -----------------------------------------------------------------------------
// Approach 1: Recursive Binary Search
// -----------------------------------------------------------------------------
// Idea:
// - Check mid and compare with nums[mid+1].
// - If nums[mid] > nums[mid+1], search left half (including mid).
// - Otherwise, search right half (mid+1 ... right).
// - Base case: when left == right, that's the peak index.
//
// Time Complexity: O(log n)
// Space Complexity: O(log n) due to recursion stack
//
class Solution {
public:
    int rec_binarySearch(vector<int>& nums, int left, int right){
        if (left == right) {
            return left;
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid+1]) {
            return rec_binarySearch(nums, left, mid);
        } else {
            return rec_binarySearch(nums, mid+1, right);
        }
    }
    
    int findPeakElement(vector<int>& nums) {
        return rec_binarySearch(nums, 0, nums.size()-1);
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Iterative Binary Search
// -----------------------------------------------------------------------------
// Idea:
// - Same logic as recursive but done iteratively.
// - Shrink search space until left == right.
// - That index is the peak.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)
//
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid+1]) {
                right = mid;        // peak lies in left half
            } else {
                left = mid + 1;     // peak lies in right half
            }
        }
        return left; // or right (same at this point)
    }
};
