/*
Problem: Gas Station (LeetCode #134)
--------------------------------------
Given two integer arrays `gas` and `cost` of length `n`:  
- `gas[i]` is the amount of gas at station `i`.  
- `cost[i]` is the gas required to travel from station `i` to `(i+1) % n`.  

Return the starting gas station index if you can complete the circuit once clockwise, otherwise return -1.

Examples:
---------
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]  
Output: 3  

Input: gas = [2,3,4], cost = [3,4,3]  
Output: -1

Constraints:
------------
- 1 <= gas.length == cost.length <= 10^5  
- 0 <= gas[i], cost[i] <= 10^4  
*/

// -----------------------------------------------------------------------------
// Approach: Greedy + One Pass
// -----------------------------------------------------------------------------
// Idea:
// 1. Check total gas vs total cost; if total gas < total cost, return -1.
// 2. Traverse stations maintaining current gas balance `currGas`.
// 3. If `currGas` drops below 0, reset start to next station and `currGas = 0`.
// 4. The start index found after the loop is the valid starting station.
//
// Why this works:
// - If you fail at station i, any station before i+1 cannot be the start.
// - Only one pass is needed since the total gas >= total cost.
//
// Time Complexity: O(n)  
// Space Complexity: O(1)
// -----------------------------------------------------------------------------
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas = 0, totCost = 0;

        // Step 1: Calculate total gas and total cost
        for (int val : gas) totGas += val;
        for (int val : cost) totCost += val;

        // Step 2: If total gas < total cost, circuit impossible
        if (totGas < totCost) return -1;

        int start = 0;   // candidate starting station
        int currGas = 0; // current gas balance

        // Step 3: Traverse stations
        for (int i = 0; i < gas.size(); i++) {
            currGas += (gas[i] - cost[i]);

            // If current gas < 0, move start to next station
            if (currGas < 0) {
                start = i + 1;
                currGas = 0;
            }
        }

        // Step 4: Return starting station
        return start;
    }
};
