/*
Problem: Product of Array Except Self (LeetCode #238)
------------------------------------------------------
Given an integer array nums of length n, return an array answer such that 
answer[i] is equal to the product of all the elements of nums except nums[i].

You must write an algorithm that runs in O(n) time and without using 
the division operation.

Examples:
----------
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Constraints:
-------------
- 2 <= nums.length <= 10^5
- -30 <= nums[i] <= 30
- The product of any prefix or suffix fits in a 32-bit integer.
*/


// -----------------------------------------------------------------------------
// Approach 0: Brute Force
// -----------------------------------------------------------------------------
// Idea:
// - For each element nums[i], multiply all other elements except nums[i].
// - Nested loop approach.
//
// Time Complexity: O(n^2)
// Space Complexity: O(1) (ignoring output array)
// Not efficient for n up to 1e5.
//

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    ans[i] *= nums[j];
                }
            }
        }
        return ans;
    }
};


// -----------------------------------------------------------------------------
// Approach 1: Prefix & Suffix Arrays
// -----------------------------------------------------------------------------
// Idea:
// - Use prefix[i] = product of all nums before i.
// - Use suffix[i] = product of all nums after i.
// - answer[i] = prefix[i] * suffix[i].
//
// Time Complexity: O(n)
// Space Complexity: O(n) for prefix & suffix.
//

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for (int i = n-2; i >= 0; i--) {
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Optimized Prefix + Suffix (O(1) extra space)
// -----------------------------------------------------------------------------
// Idea:
// - First pass: build ans[] using prefix product (product of all before i).
// - Second pass: multiply with running suffix product (product of all after i).
// - Avoids extra arrays.
//
// Time Complexity: O(n)
// Space Complexity: O(1) (excluding output array)
//

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Prefix pass
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i-1] * nums[i-1];
        }

        // Suffix pass
        int suffix = 1;
        for (int i = n-2; i >= 0; i--) {
            suffix *= nums[i+1];
            ans[i] *= suffix;
        }
        return ans;
    }
};
