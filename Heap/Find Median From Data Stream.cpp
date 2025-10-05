/*
Problem: Find Median from Data Stream (LeetCode #295)
-----------------------------------------------------
The task is to design a data structure `MedianFinder` that supports:
1. `addNum(int num)` - Add a number from the data stream.
2. `findMedian()` - Return the median of all numbers added so far.

Example:
--------
Input:
MedianFinder mf;
mf.addNum(1);
mf.addNum(2);
mf.findMedian(); // returns 1.5
mf.addNum(3);
mf.findMedian(); // returns 2

Explanation:
------------
- Numbers = [1, 2] → Median = (1 + 2) / 2 = 1.5
- Numbers = [1, 2, 3] → Median = 2 (middle element)

Constraints:
------------
- -10^5 <= num <= 10^5
- At most 5 * 10^4 calls will be made to addNum and findMedian.
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Two Heaps (Max-Heap + Min-Heap)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - Maintain two heaps:
//    1. `leftHalf` (max-heap): stores the smaller half of numbers
//    2. `rightHalf` (min-heap): stores the larger half of numbers
// - Always ensure that:
//    - |size(leftHalf) - size(rightHalf)| ≤ 1
//    - All elements in `leftHalf` ≤ all elements in `rightHalf`
//
// - The median is then either:
//    - Top of `leftHalf` (if odd count and left is bigger)
//    - Top of `rightHalf` (if odd count and right is bigger)
//    - Average of both tops (if even count)
//
// 📊 Complexity:
// - ⏱️ Time Complexity: O(log N) per insertion (heap push/pop)
// - ⏱️ Time Complexity: O(1) per findMedian()
// - 📦 Space Complexity: O(N) to store all numbers
// -----------------------------------------------------------------------------
class MedianFinder {
private:
    priority_queue<int> leftHalf; // max-heap for smaller half
    priority_queue<int, vector<int>, greater<int>> rightHalf; // min-heap for larger half

public:
    MedianFinder() {}

    // Insert a number into the data structure
    void addNum(int num) {
        if (leftHalf.empty()) {
            leftHalf.push(num);
        } else {
            int leftTop = leftHalf.top();
            int rightTop = rightHalf.empty() ? INT_MIN : rightHalf.top();

            // Decide which heap to push into
            if (num > leftTop && num > rightTop) {
                rightHalf.push(num);
            } else {
                leftHalf.push(num);
            }

            // Rebalance if size difference > 1
            int sizeDiff = abs((int)leftHalf.size() - (int)rightHalf.size());
            if (sizeDiff > 1) {
                if (leftHalf.size() > rightHalf.size()) {
                    rightHalf.push(leftHalf.top());
                    leftHalf.pop();
                } else {
                    leftHalf.push(rightHalf.top());
                    rightHalf.pop();
                }
            }
        }
    }

    // Return the median of all numbers added so far
    double findMedian() {
        if (leftHalf.size() == rightHalf.size()) {
            if (leftHalf.empty()) return 0.0; // No elements
            return (leftHalf.top() + rightHalf.top()) / 2.0;
        }
        return (leftHalf.size() > rightHalf.size()) ? leftHalf.top() : rightHalf.top();
    }
};
