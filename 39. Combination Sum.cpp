// Title: Combination Sum
// Leetcode Problem: https://leetcode.com/problems/combination-sum/
// Difficulty: Medium

/*
    Problem Description:
    Given an array of distinct integers candidates and a target integer target,
    return a list of all unique combinations of candidates where the chosen numbers sum to target.
    You may return the combinations in any order.

    The same number may be chosen from candidates an unlimited number of times.
    Two combinations are unique if the frequency of at least one of the chosen numbers is different.

    Example:
    Input: candidates = [2,3,6,7], target = 7
    Output: [[2,2,3],[7]]

    Constraints:
    - 1 <= candidates.length <= 30
    - 2 <= candidates[i] <= 40
    - All elements of candidates are distinct.
    - 1 <= target <= 500

    Approach:
    - Use backtracking to explore all combinations.
    - Try each candidate starting from current index (to allow repeated use).
    - If the current sum exceeds target, backtrack.
    - If it matches the target, store the combination.

    Time Complexity: O(2^target)
    Space Complexity: O(target)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& res,
                   vector<int>& combi, int sum, int index) {
        if (sum == target) {
            res.push_back(combi);
            return;
        }
        if (sum > target) return;

        for (int i = index; i < candidates.size(); ++i) {
            combi.push_back(candidates[i]);
            backtrack(candidates, target, res, combi, sum + candidates[i], i); // Reuse allowed
            combi.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combi;
        backtrack(candidates, target, res, combi, 0, 0);
        return res;
    }
};

// Optional: Driver code to test locally
/*
int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = sol.combinationSum(candidates, target);

    for (const auto& comb : result) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
*/
