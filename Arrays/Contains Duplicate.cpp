/*
Problem: Contains Duplicate (LeetCode #217)
-------------------------------------------
Given an integer array nums, return true if any value appears at least twice
in the array, and return false if every element is distinct.

Example:
---------
Input: nums = [1,2,3,1]
Output: true

Input: nums = [1,2,3,4]
Output: false

Constraints:
------------
- 1 <= nums.length <= 10^5
- -10^9 <= nums[i] <= 10^9
*/


// -----------------------------------------------------------------------------
// Approach 1: Sorting
// -----------------------------------------------------------------------------
/*
Idea:
- If we sort the array, any duplicate elements will be adjacent.
- Just check consecutive elements to see if they are equal.

Time Complexity: O(n log n)  (due to sorting)
Space Complexity: O(1)       (ignoring sort's stack usage)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
};


// -----------------------------------------------------------------------------
// Approach 2: HashSet
// -----------------------------------------------------------------------------
/*
Idea:
- Use an unordered_set to track seen numbers.
- If a number is already in the set, we found a duplicate.
- Otherwise, insert it.

Time Complexity: O(n) average case
Space Complexity: O(n)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            if (s.count(num) > 0)   // duplicate found
                return true;
            s.insert(num);          // add number to set
        }
        return false;
    }
};
