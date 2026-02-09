/*
Problem: Sort Array By Parity (LeetCode #905)
---------------------------------------------
Given an integer array `nums`, move all the even integers to the beginning
of the array followed by all the odd integers.

You may return any array that satisfies this condition.

Example:
--------
Input:  nums = [3,1,2,4]
Output: [2,4,3,1]
(Any order where all evens come before odds is valid)

Constraints:
------------
- 1 <= nums.length <= 5000
- 0 <= nums[i] <= 5000
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Extra Array (Two Pass)
// -----------------------------------------------------------------------------
// 🔹 Idea:
// - Traverse array once and store all even numbers
// - Traverse again and store all odd numbers
// - Maintains relative order
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(n)
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result;

        // collect even numbers
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                result.push_back(nums[i]);
            }
        }

        // collect odd numbers
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) {
                result.push_back(nums[i]);
            }
        }

        return result;
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 2: Two Pointers with Extra Array
// -----------------------------------------------------------------------------
// 🔹 Idea:
// - Use two pointers:
//   - `left` for even placement (start)
//   - `right` for odd placement (end)
// - Traverse once and place elements directly
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(n)
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        vector<int> result(nums.size());

        for (int num : nums) {
            if (num % 2 == 0) {
                result[left++] = num;
            } else {
                result[right--] = num;
            }
        }
        return result;
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 3: In-Place Two Pointers
// -----------------------------------------------------------------------------
// 🔹 Idea:
// - Maintain two pointers from both ends
// - If left is odd → swap with right
// - If left is even → move forward
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(1)
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            if (nums[left] % 2 == 0) {
                left++;
            } else {
                swap(nums[left], nums[right]);
                right--;
            }
        }
        return nums;
    }
};
