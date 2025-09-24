// 🚀 Leetcode 40 - Combination Sum II (100% Runtime & Memory in C++) 🔥
// Backtracking with Duplicate Skipping | Clean & Optimized Solution
// Problem Link: https://leetcode.com/problems/combination-sum-ii/
// Difficulty: Medium
// Tags: Backtracking, Recursion, Combinations, Pruning

/*
    Problem:
    Given a collection of candidate numbers (candidates) and a target number (target),
    find all unique combinations in candidates where the candidate numbers sum to target.

    Each number in candidates may only be used once in the combination.
    Note: The solution set must not contain duplicate combinations.

    Example:
    Input: candidates = [10,1,2,7,6,1,5], target = 8
    Output:
        [
          [1,1,6],
          [1,2,5],
          [1,7],
          [2,6]
        ]

    Approach:
    - Sort the input array to group duplicates.
    - Use backtracking:
        * Add current combination if target is reached.
        * Skip over duplicates (if i > index && candidates[i] == candidates[i-1]).
        * Use each number at most once by moving to i + 1 in recursion.
    - Backtrack by removing the last added number.

    Time Complexity: O(2^n)
        - Each number can be picked or skipped.
    Space Complexity: O(n)
        - Depth of the recursion stack (up to number of elements).
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void backtrack(vector<int>& candidates, vector<vector<int>>& res, vector<int>& combi,
                   int target, int sum, int index, int n) {
        if (sum == target) {
            res.push_back(combi);
            return;
        }
        if (sum > target) return;

        for (int i = index; i < n; i++) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            combi.push_back(candidates[i]);
            backtrack(candidates, res, combi, target, sum + candidates[i], i + 1, n);
            combi.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combi;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        backtrack(candidates, res, combi, target, 0, 0, n);
        return res;
    }
};

// Optional: Local test driver
/*
int main() {
    Solution sol;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    for (const auto& comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
*/
