/*
Problem: Sort Characters By Frequency (LeetCode #451)
------------------------------------------------------
Given a string `str`, rearrange the characters so that characters with 
higher frequency appear first. Return any valid answer.

Example:
--------
Input: str = "tree"
Output: "eetr" or "eert"

Explanation:
- 'e' appears twice
- 't' and 'r' appear once
- Characters with higher frequency come first.

Constraints:
------------
- 1 <= str.length <= 5 * 10^5
- str consists of English letters, digits, symbols, and spaces.
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Max-Heap by Frequency
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Count frequency of each character using a hash map.
// - Use a max-heap (priority queue) to order characters by frequency.
// - Pop elements from heap and append character count times.
//
// ⏱️ Time Complexity: O(N log N) — N = length of string (heap operations)
// 📦 Space Complexity: O(N) — hash map + heap + result string
// -----------------------------------------------------------------------------
class Solution {
public:
    string frequencySort(string str) {
        unordered_map<char, int> freqMap;
        for (char ch : str) {
            freqMap[ch]++;
        }

        priority_queue<pair<int, char>> maxHeap; // {frequency, character}
        for (auto &entry : freqMap) {
            maxHeap.push({entry.second, entry.first});
        }

        string result;
        while (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();
            result.append(count, ch); // append 'ch' count times
        }

        return result;
    }
};
