/*
Problem: Sort Colors (LeetCode #75)
----------------------------------
Given an array `nums` with n objects colored red, white, or blue,
sort them in-place so that objects of the same color are adjacent.

We use the integers:
- 0 → Red
- 1 → White
- 2 → Blue

Example:
--------
Input:  nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Constraints:
------------
- n == nums.length
- 1 <= n <= 300
- nums[i] ∈ {0,1,2}
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Brute Force Sorting
// -----------------------------------------------------------------------------
// 🔹 Idea:
// - Compare every pair of elements
// - Swap if out of order
//
// ⏱ Time Complexity: O(n²)
// 📦 Space Complexity: O(1)
// -----------------------------------------------------------------------------
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


/*
---------------------------------------------------------------------------
✅ Approach 2: Counting Sort
---------------------------------------------------------------------------
🔹 Idea:
- Count how many 0s, 1s, and 2s are present
- Rewrite the array using those counts

⏱ Time Complexity: O(n)
📦 Space Complexity: O(1)
---------------------------------------------------------------------------
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;

        // Count occurrences
        for (int num : nums) {
            if (num == 0) count0++;
            else if (num == 1) count1++;
            else count2++;
        }

        // Overwrite array
        int idx = 0;
        while (count0--) nums[idx++] = 0;
        while (count1--) nums[idx++] = 1;
        while (count2--) nums[idx++] = 2;
    }
};


/*
---------------------------------------------------------------------------
✅ Approach 3: Dutch National Flag Algorithm (Optimal)
---------------------------------------------------------------------------
🔹 Idea:
- Maintain three regions:
  [0 … low-1]     → 0s
  [low … mid-1]   → 1s
  [high+1 … end]  → 2s
- Traverse once and swap accordingly

⏱ Time Complexity: O(n)
📦 Space Complexity: O(1)
---------------------------------------------------------------------------
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
            } 
            else if (nums[mid] == 1) {
                mid++;
            } 
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
