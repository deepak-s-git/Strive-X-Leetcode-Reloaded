/*
Problem: Subarray Product Less Than K (LeetCode #713)
-----------------------------------------------------
Given an array of positive integers nums and an integer k, 
return the number of contiguous subarrays where the product 
of all the elements in the subarray is strictly less than k.

Examples:
---------
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]

Constraints:
------------
- 1 <= nums.length <= 3 * 10^4
- 1 <= nums[i] <= 1000
- 0 <= k <= 10^6
*/


// -----------------------------------------------------------------------------
// Approach 1: Brute Force (O(n^2))
// -----------------------------------------------------------------------------
/*
Idea:
- Generate all possible subarrays (i...j).
- Compute product of each subarray.
- If product < k, increment count.
- Stop inner loop early if product >= k.

Time Complexity: O(n^2) in worst case
Space Complexity: O(1)
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                if (prod >= k) break;   // stop early if product too large
                ans++;
            }
        }
        return ans;
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Sliding Window (Optimal, O(n))
// -----------------------------------------------------------------------------
/*
Idea:
- Maintain a sliding window [i...j] where product < k.
- Expand right pointer (j), multiplying into product.
- If product >= k, shrink window from left (i++).
- All subarrays ending at j are valid (count = j - i + 1).

Time Complexity: O(n)
    - each element is visited at most twice (once by j, once by i).
Space Complexity: O(1)
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;  // edge case: no subarray can satisfy

        int n = nums.size();
        int ans = 0;
        int prod = 1, i = 0;

        for (int j = 0; j < n; j++) {
            prod *= nums[j];

            while (prod >= k && i <= j) {
                prod /= nums[i];
                i++;
            }

            ans += (j - i + 1);  // all subarrays ending at j
        }
        return ans;
    }
};
