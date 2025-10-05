/*
Problem: Maximum Frequency Stack (LeetCode #895)
-------------------------------------------------
Design a stack-like data structure `FreqStack` that supports the following operations:

1. `push(int val)` - Push an integer `val` onto the stack.
2. `pop()` - Removes and returns the most frequent element in the stack.
   - If there is a tie for the most frequent element, return the one closest to the top of the stack.

Example:
--------
Input:
FreqStack freqStack;
freqStack.push(5);
freqStack.push(7);
freqStack.push(5);
freqStack.push(7);
freqStack.push(4);
freqStack.push(5);

Output:
freqStack.pop(); // returns 5
freqStack.pop(); // returns 7
freqStack.pop(); // returns 5
freqStack.pop(); // returns 4

Explanation:
-----------
- The most frequent element is 5 (appears 3 times), so the first pop is 5.
- Now 5 and 7 both appear twice, but 7 is on top, so pop() returns 7.
- Now 5 appears twice and is most frequent again, so pop() returns 5.
- Finally, 4, 7 each appear once, but 4 is on top, so pop() returns 4.

Constraints:
------------
- 1 <= val <= 10^9
- At most 2 * 10^4 calls will be made to push and pop.
*/


// -----------------------------------------------------------------------------
// ✅ Approach: Max-Heap + Frequency Map (Greedy + Priority Queue)
// -----------------------------------------------------------------------------
// 🔥 Intuition:
// - We want to pop the element with the highest frequency.
// - If multiple elements have the same frequency, we want the one pushed last.
// - We use a `priority_queue` (max-heap) storing: {frequency, {index, value}}
//   - `frequency` ensures we pop the most frequent first
//   - `index` ensures we pop the most recently pushed among equals
//
// 📊 Complexity:
// - ⏱️ Time Complexity: O(log N) for push and pop (due to heap operations)
// - 📦 Space Complexity: O(N) for storing all pushed elements and frequencies
// -----------------------------------------------------------------------------
class FreqStack {
private:
    // Max-heap stores {frequency, {pushIndex, value}}
    priority_queue<pair<int, pair<int, int>>> maxHeap;
    // Frequency map to store frequency of each element
    unordered_map<int, int> frequency;
    // Push index to track the order of insertion
    int currentIndex = 0;

public:
    FreqStack() {}

    // Push a value onto the stack
    void push(int value) {
        frequency[value]++;  // Increment frequency
        // Push tuple: {frequency, {index, value}} for correct priority
        maxHeap.push({frequency[value], {currentIndex, value}});
        currentIndex++;
    }

    // Pop the most frequent element (or most recent among equals)
    int pop() {
        auto topElement = maxHeap.top();
        maxHeap.pop();

        int value = topElement.second.second;
        frequency[value]--; // Decrease frequency

        return value;
    }
};
