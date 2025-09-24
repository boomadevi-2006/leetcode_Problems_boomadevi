// 🚀 Leetcode 90 - Subsets II (100% Runtime & Memory in C++) 🔥
// Backtracking with Duplicate Skipping | Clean & Optimized Solution
// Problem Link: https://leetcode.com/problems/subsets-ii/
// Difficulty: Medium
// Tags: Backtracking, Recursion, Subsets, Duplicate Handling

/*
    Problem:
    Given an integer array `nums` that may contain duplicates, return all possible subsets (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.

    Example:
    Input: nums = [1,2,2]
    Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

    Approach:
    - Sort the array to group duplicates together.
    - Use backtracking to explore all subsets.
    - Skip duplicates using: if (i > current_index && nums[i] == nums[i - 1]) continue;
    - Backtrack after each recursive call to explore all paths.

    Time Complexity: O(2^n)
        - Generates all possible subsets (with some pruning).
    Space Complexity: O(n)
        - Recursion stack and current subset.

    Language: C++
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void backtrack(vector<int> &nums, vector<vector<int>> &res, vector<int> &combi, int n, int index) {
        res.push_back(combi);

        for (int i = index; i < n; i++) {
            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1]) continue;

            combi.push_back(nums[i]);
            backtrack(nums, res, combi, n, i + 1);
            combi.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> combi;
        sort(nums.begin(), nums.end()); // Sort to group duplicates
        backtrack(nums, res, combi, n, 0);
        return res;
    }
};

// Optional: Local test driver
/*
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = sol.subsetsWithDup(nums);

    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
*/
