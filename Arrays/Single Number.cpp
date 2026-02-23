/*
Problem: Single Number (LeetCode #136)
--------------------------------------
Given a non-empty array of integers `nums`,
every element appears twice except for one.

Find that single one.

Example:
--------
Input:  nums = [2,2,1]
Output: 1

Input:  nums = [4,1,2,1,2]
Output: 4

Constraints:
------------
- 1 <= nums.length <= 3 * 10^4
- -3*10^4 <= nums[i] <= 3*10^4
- Every element appears twice except one
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Sorting
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Sort the array
// - Equal numbers will be adjacent
// - Traverse in pairs and find mismatch
//
// ⏱ Time Complexity: O(n log n)
// 📦 Space Complexity: O(1)
// -----------------------------------------------------------------------------
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 1; i < n; i += 2){
            if(nums[i] != nums[i - 1])
                return nums[i - 1];
        }
        return nums[n - 1];
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 2: Hash Map
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Count frequency of each number
// - Return the number with frequency 1
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(n)
// -----------------------------------------------------------------------------
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int num : nums){
            freq[num]++;
        }

        for(auto it : freq){
            if(it.second == 1)
                return it.first;
        }
        return -1;
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 3: Bit Manipulation (XOR Trick) — Optimal
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - XOR properties:
//   a ^ a = 0
//   a ^ 0 = a
// - Since every number appears twice except one,
//   all duplicates cancel out
//
// Example:
// 4 ^ 1 ^ 2 ^ 1 ^ 2
// = (1^1) ^ (2^2) ^ 4
// = 0 ^ 0 ^ 4
// = 4
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(1)
// -----------------------------------------------------------------------------
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(int num : nums){
            ans ^= num;
        }
        return ans;
    }
};