/*
Problem: Sort Colors (LeetCode #75)
-----------------------------------
Given an array nums with n objects colored red, white, or blue, 
sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red (0), white (1), and blue (2).

You must solve this problem without using the library's sort function.

Examples:
---------
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Input: nums = [2,0,1]
Output: [0,1,2]

Constraints:
------------
- n == nums.length
- 1 <= n <= 300
- nums[i] is either 0, 1, or 2
*/


// -----------------------------------------------------------------------------
// Approach 1: Brute Force Sorting (O(n^2))
// -----------------------------------------------------------------------------
/*
Idea:
- Use simple nested loops to compare and swap elements (selection/bubble style).
- Sorts the array but inefficient.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                }
            }
        }
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Dutch National Flag Algorithm (Optimal, O(n))
// -----------------------------------------------------------------------------
/*
Idea:
- Maintain 3 partitions:
    0 to low-1     → all 0s
    low to mid-1   → all 1s
    high+1 to end  → all 2s
- Traverse with mid pointer and swap accordingly.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
