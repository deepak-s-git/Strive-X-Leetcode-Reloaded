/*
Problem: Find All Numbers Disappeared in an Array (LeetCode #448)
-----------------------------------------------------------------
Given an array `nums` of size n where:
- 1 <= nums[i] <= n
- Some elements appear twice and others appear once

Return all the numbers in the range [1, n] that do NOT appear in nums.

Example:
--------
Input:  nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Explanation:
Numbers 5 and 6 are missing from the range 1 to 8.

Constraints:
------------
- n == nums.length
- 1 <= n <= 10^5
- 1 <= nums[i] <= n
- Some elements appear twice
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Using Hash Set
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Insert all elements into a set
// - Traverse from 1 to n
// - If a number is not in set → it's missing
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(n)
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> result;

        for(int i = 1; i <= nums.size(); i++){
            if(s.find(i) == s.end())
                result.push_back(i);
        }
        return result;
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 2: In-Place Marking (Optimal)
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Since numbers are in range [1, n]
// - Use index marking trick
// - For each number x → mark nums[x-1] as negative
// - At end, positive indices indicate missing numbers
//
// ⚠️ Important:
// We use abs() because value might already be negative
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(1) (excluding output)
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};