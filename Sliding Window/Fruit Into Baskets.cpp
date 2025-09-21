/*
Problem: Fruit Into Baskets (LeetCode #904)
--------------------------------------------
You are visiting a row of fruit trees represented by an integer array `fruits` 
where `fruits[i]` is the type of fruit the i-th tree produces.

You want to collect as much fruit as possible under the following rules:
- You have only two baskets.
- Each basket can only hold one type of fruit.
- Once you start picking from a tree, you must continue picking from every 
  consecutive tree until you encounter a tree that makes it impossible 
  (because you'd have to pick a third type of fruit).

Return the maximum number of fruits you can pick.

Example:
--------
Input: fruits = [1,2,1]
Output: 3
Explanation: Pick from all trees.

Constraints:
------------
- 1 <= fruits.length <= 10^5
- 0 <= fruits[i] < fruits.length
*/

// -----------------------------------------------------------------------------
// Approach: Sliding Window + HashMap
// -----------------------------------------------------------------------------
// Idea:
// - Maintain a window [left, right] such that it contains at most 2 distinct fruit types.
// - Use an unordered_map to count the number of fruits of each type in the window.
// - If the window has more than 2 distinct fruits, shrink it from the left.
// - Update maxLen as the largest window size seen so far.
//
// Time Complexity: O(n)   -> each element is added/removed from map at most once
// Space Complexity: O(1)  -> at most 2 keys in the map
//
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, maxLen = 0;
        unordered_map<int, int> basket;  // fruitType -> count

        for (int right = 0; right < fruits.size(); right++) {
            basket[fruits[right]]++;

            // Shrink window if more than 2 types of fruits
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
