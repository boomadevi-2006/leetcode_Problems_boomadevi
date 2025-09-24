// Title: Subsets - Leetcode Problem #78
// File: 78. Subsets.cpp
// Difficulty: Medium
// Tags: Backtracking, Recursion, Bit Manipulation (alternate approach)
// Problem Link: https://leetcode.com/problems/subsets/

/*
    Problem:
    Given an integer array nums of unique elements, return all possible subsets (the power set).
    The solution set must not contain duplicate subsets. Return the solution in any order.

    Example:
    Input: nums = [1,2,3]
    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

    Approach:
    - Use backtracking to explore all combinations of elements.
    - At each recursion step:
        * Add the current combination to the result.
        * Recurse by including the current element and moving to the next.
        * Backtrack by removing the last included element.

    Time Complexity: O(2^n)
        - Each element can either be included or excluded.
    Space Complexity: O(n)
        - Depth of recursion stack and current combination.

    Language: C++
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void backtrack(vector<int> &nums, vector<int> &combi, vector<vector<int>> &res, int n, int c) {
        res.push_back(combi);  // Add current subset

        for (int i = c; i < n; i++) {
            combi.push_back(nums[i]);                     // Include nums[i]
            backtrack(nums, combi, res, n, i + 1);        // Recurse for next index
            combi.pop_back();                             // Backtrack
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> combi;
        backtrack(nums, combi, res, n, 0);
        return res;
    }
};

// Optional: Driver code to test the function
/*
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.subsets(nums);

    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
*/
