/*
Problem: Trapping Rain Water (LeetCode #42)
-------------------------------------------
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

Examples:
---------
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Input: height = [4,2,0,3,2,5]
Output: 9

Constraints:
------------
- n == height.length
- 1 <= n <= 2 * 10^4
- 0 <= height[i] <= 10^5
*/


// -----------------------------------------------------------------------------
// Approach 1: Brute Force (O(n^2))
// -----------------------------------------------------------------------------
/*
Idea:
- For each index i, find the max height to its left and max height to its right.
- Water trapped on i = min(leftMax, rightMax) - height[i].
- Sum over all i.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int lmax = 0, rmax = 0;

            for (int j = 0; j <= i; j++) {
                lmax = max(lmax, height[j]);
            }
            for (int j = i; j < n; j++) {
                rmax = max(rmax, height[j]);
            }

            ans += min(lmax, rmax) - height[i];
        }
        return ans;
    }
};


// -----------------------------------------------------------------------------
// Approach 2: Prefix & Suffix Precomputation (O(n))
// -----------------------------------------------------------------------------
/*
Idea:
- Precompute leftMax[i] = max height from [0..i].
- Precompute rightMax[i] = max height from [i..n-1].
- Water trapped at i = min(leftMax[i], rightMax[i]) - height[i].

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        rightMax[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};


// -----------------------------------------------------------------------------
// Approach 3: Two-Pointer Technique (Optimal, O(n))
// -----------------------------------------------------------------------------
/*
Idea:
- Maintain two pointers (l, r) at both ends, and keep track of current lmax and rmax.
- Water trapped depends on the smaller of lmax and rmax:
    - If lmax < rmax: trapped water = lmax - height[l], then move l++.
    - Else: trapped water = rmax - height[r], then move r--.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0, r = n-1;
        int lmax = 0, rmax = 0;

        while (l < r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if (lmax < rmax) {
                ans += lmax - height[l];
                l++;
            } else {
                ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};
