/*
Problem: Sort Array By Parity II (LeetCode #922)
-----------------------------------------------
Given an array `nums` of even length, where exactly half of the integers are even
and half are odd, sort the array so that:

- nums[even index] is even
- nums[odd index]  is odd

Return any valid arrangement.

Example:
--------
Input:  nums = [4,2,5,7]
Output: [4,5,2,7]

Explanation:
- Index 0 → even → 4
- Index 1 → odd  → 5
- Index 2 → even → 2
- Index 3 → odd  → 7

Constraints:
------------
- 2 <= nums.length <= 20000
- nums.length is even
- Half of the integers are even
- Half of the integers are odd
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Extra Array with Even & Odd Index Pointers
// -----------------------------------------------------------------------------
// 🔹 Idea:
// - Maintain two pointers:
//   - `even` starting at index 0
//   - `odd` starting at index 1
// - Traverse through nums
// - Place even numbers at even indices
// - Place odd numbers at odd indices
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(n)
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even = 0;
        int odd = 1;

        vector<int> result(nums.size());

        for (int num : nums) {
            if (num % 2 == 0) {
                result[even] = num;
                even += 2;
            } else {
                result[odd] = num;
                odd += 2;
            }
        }
        return result;
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 2: In-Place Two Pointers
// -----------------------------------------------------------------------------
// 🔹 Idea:
// - Use two pointers:
//   - `i` for even indices
//   - `j` for odd indices
// - If nums[i] is correct (even), move i
// - If nums[j] is correct (odd), move j
// - Otherwise swap nums[i] and nums[j]
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(1)
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1;

        while (i < n && j < n) {
            if (nums[i] % 2 == 0) {
                i += 2;
            } else if (nums[j] % 2 == 1) {
                j += 2;
            } else {
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};
