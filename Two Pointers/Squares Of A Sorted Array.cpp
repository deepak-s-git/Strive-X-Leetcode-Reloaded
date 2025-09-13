/*
Problem: Squares of a Sorted Array (LeetCode #977)
----------------------------------------------------
Given an integer array nums sorted in non-decreasing order,
return an array of the squares of each number sorted in non-decreasing order.

Examples:
----------
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

Constraints:
-------------
- 1 <= nums.length <= 10^4
- -10^4 <= nums[i] <= 10^4
- nums is sorted in non-decreasing order
*/


// -----------------------------------------------------------------------------
// Approach 1: Square All and Sort
// -----------------------------------------------------------------------------
/*
Idea:
- Square each element.
- Sort the squared values.

Time Complexity: O(n log n) (due to sorting)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            ans.push_back(nums[i] * nums[i]);
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Two Pointers (Optimal)
// -----------------------------------------------------------------------------
/*
Idea:
- Since array is sorted, the largest square will come from either leftmost
  (largest negative) or rightmost (largest positive).
- Use two pointers, compare abs values, and fill results from the back.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            if (abs(nums[left]) > abs(nums[right])) {
                ans[i] = nums[left] * nums[left];
                left++;
            } else {
                ans[i] = nums[right] * nums[right];
                right--;
            }
        }
        return ans;
    }
};
