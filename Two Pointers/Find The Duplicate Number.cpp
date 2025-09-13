/*
Problem: Find the Duplicate Number (LeetCode #287)
---------------------------------------------------
Given an array of integers nums containing n + 1 integers where each integer 
is in the range [1, n] inclusive. There is only one repeated number in nums, 
return this repeated number.

You must solve the problem without modifying the array nums and using 
only constant extra space.

Examples:
----------
Input: nums = [1,3,4,2,2]
Output: 2

Input: nums = [3,1,3,4,2]
Output: 3

Constraints:
-------------
- 1 <= n <= 10^5
- nums.length == n + 1
- 1 <= nums[i] <= n
- All integers in nums appear once except for exactly one integer which appears two or more times.
*/


// -----------------------------------------------------------------------------
// Approach 0: Sorting
// -----------------------------------------------------------------------------
// Idea:
// - Sort nums, then check adjacent pairs for duplicate.
// - Breaks the "don’t modify input" constraint, but works.
//
// Time Complexity: O(n log n)
// Space Complexity: O(1) if sort is in-place
//

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                return nums[i];
            }
        }
        return -1; // should never happen
    }
};


// -----------------------------------------------------------------------------
// Approach 1: Hash Map / Frequency Count
// -----------------------------------------------------------------------------
// Idea:
// - Use a hash map to track seen numbers.
// - First repeat encountered is the duplicate.
// - Violates "O(1) extra space", but simple.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
//

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> freqCount;
        for (int val : nums) {
            if (freqCount.find(val) != freqCount.end()) {
                return val;
            }
            freqCount[val] = 1;
        }
        return -1; // should never happen
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Floyd’s Cycle Detection (Tortoise & Hare)
// -----------------------------------------------------------------------------
// Idea:
// - Treat nums as a linked list where index → value pointer.
// - Since there is a duplicate, there will be a cycle.
// - Use Floyd’s cycle detection to find the duplicate number.
// - Satisfies O(1) space + doesn’t modify array.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Detect cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find entry point (duplicate number)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
