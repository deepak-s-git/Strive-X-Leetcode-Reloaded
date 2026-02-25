/*
Problem: Product of Array Except Self (LeetCode #238)
-----------------------------------------------------
Given an integer array `nums`, return an array `answer` such that
answer[i] is equal to the product of all the elements of `nums`
except nums[i].

The solution must run in O(n) time and without using division.

Example:
--------
Input:  nums = [1,2,3,4]
Output: [24,12,8,6]

Input:  nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Constraints:
------------
- 2 <= nums.length <= 10^5
- -30 <= nums[i] <= 30
- The product of any prefix or suffix fits in 32-bit integer.
*/


// -----------------------------------------------------------------------------
// ✅ Approach 1: Brute Force (Nested Loops)
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - For every index i
// - Multiply all elements except nums[i]
//
// ⏱ Time Complexity: O(n²)
// 📦 Space Complexity: O(1) extra (excluding output)
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j){
                    ans[i] *= nums[j];
                }
            }
        }
        return ans;
    }
};


 // -----------------------------------------------------------------------------
// ✅ Approach 2: Prefix + Suffix Arrays
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - prefix[i]  = product of all elements before i
// - suffix[i]  = product of all elements after i
// - answer[i] = prefix[i] * suffix[i]
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(n)
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for(int i = n - 2; i >= 0; i--){
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < n; i++){
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};


// -----------------------------------------------------------------------------
// ✅ Approach 3: Optimized Prefix + Running Suffix (No Extra Arrays)
// -----------------------------------------------------------------------------
// 🔹 Intuition:
// - First pass: store prefix products directly in answer array
// - Second pass: multiply with running suffix product
// - Eliminates need for separate suffix array
//
// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(1) extra (excluding output)
// -----------------------------------------------------------------------------
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        for(int i = 1; i < n; i++){
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int suffix = 1;
        for(int i = n - 2; i >= 0; i--){
            suffix *= nums[i + 1];
            ans[i] *= suffix;
        }

        return ans;
    }
};