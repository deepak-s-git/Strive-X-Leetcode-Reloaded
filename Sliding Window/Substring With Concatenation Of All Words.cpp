/*
Problem: Substring with Concatenation of All Words (LeetCode #30)
-----------------------------------------------------------------
You are given a string s and an array of strings words, where all words 
are of the same length. Return all starting indices of substring(s) in s 
that is a concatenation of each word in words exactly once and without 
any intervening characters. You can return the answer in any order.

Examples:
---------
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]

Constraints:
------------
- 1 <= s.length <= 10^4
- 1 <= words.length <= 5000
- 1 <= words[i].length <= 30
- s and words[i] consist of lowercase English letters.
*/


// -----------------------------------------------------------------------------
// Approach: Sliding Window with Frequency Maps
// -----------------------------------------------------------------------------
// Idea:
// - Each valid substring has total length = wordLen * wordCount.
// - Precompute the target frequency of words in `words`.
// - For each offset in [0, wordLen), slide over s in chunks of `wordLen`.
// - Maintain a frequency map for the current window and count of matched words.
// - If a word appears too many times, shrink from the left until valid.
// - If exactly wordCount words match, record starting index.
// - Reset window if an invalid word is encountered.
//
// Time Complexity: O(n * wordLen) ≈ O(n) (each word processed at most twice)
// Space Complexity: O(#unique words)
//
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        int n = s.size();

        unordered_map<string, int> targetFreq;
        for (auto &w : words) {
            targetFreq[w]++;
        }

        for (int offset = 0; offset < wordLen; offset++) {
            unordered_map<string, int> windowFreq;
            int left = offset, matchedCount = 0;

            for (int right = offset; right + wordLen <= n; right += wordLen) {
                string word = s.substr(right, wordLen);

                if (targetFreq.count(word)) {
                    windowFreq[word]++;
                    matchedCount++;

                    // Shrink if a word is over-counted
                    while (windowFreq[word] > targetFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowFreq[leftWord]--;
                        left += wordLen;
                        matchedCount--;
                    }

                    // Found a valid substring
                    if (matchedCount == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    windowFreq.clear();
                    matchedCount = 0;
                    left = right + wordLen;
                }
            }
        }

        return result;
    }
};
