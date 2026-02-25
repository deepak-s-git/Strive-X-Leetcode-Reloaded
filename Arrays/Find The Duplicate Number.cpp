/*
Problem: Find the Duplicate Number (LeetCode #287)
--------------------------------------------------
Given an array of integers `nums` containing n + 1 integers where
each integer is in the range [1, n] inclusive.

There is only ONE repeated number in `nums`, return this repeated number.

You must solve the problem:
- Without modifying the array
- Using only constant extra space

Example:
--------
Input:  nums = [1,3,4,2,2]
Output: 2

Input:  nums = [3,1,3,4,2]
Output: 3

Constraints:
------------
- 1 <= n <= 10^5
- nums.length == n + 1
- 1 <= nums[i] <= n
- Only one duplicate number exists (may repeat multiple times)
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Sorting
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Sort the array.
// - Duplicate elements will become adjacent.
// - Traverse and check nums[i] == nums[i-1].
//
// ⏱ Time Complexity: O(n log n)
// 📦 Space Complexity: O(1) or O(log n) depending on sort
// ⚠️ Modifies array (Not allowed in strict constraint)
// -----------------------------------------------------------------------------
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1]){
                return nums[i];
            }
        }
        return -1;
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 2: Using Hash Map
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Use a frequency map.
// - If number already seen → duplicate found.
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(n)
// -----------------------------------------------------------------------------
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int num : nums){
            if(freq.find(num) != freq.end()){
                return num;
            }
            freq[num] = 1;
        }
        return -1;
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 3: Floyd's Cycle Detection (Tortoise & Hare)
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - Treat array as a linked list:
//   index → value at that index
// - Since values are in range [1, n], it forms a cycle.
// - Duplicate number is the entry point of the cycle.
//
// Step 1: Detect intersection using slow & fast pointers.
// Step 2: Move one pointer to start.
// Step 3: Move both one step at a time → meet at duplicate.
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(1)
// -----------------------------------------------------------------------------
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Detect cycle
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        // Phase 2: Find cycle entry
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};