// 🌟 CPP | 💯 Clean & Efficient Backtracking | ✅ Leetcode 216 - Combination Sum III
// Problem Link: https://leetcode.com/problems/combination-sum-iii/
// Tags: Backtracking, Recursion, Combinations
// Difficulty: Medium
// Beats 100% Runtime & Memory (C++)

/*
    Problem:
    Find all possible combinations of k numbers that add up to a number n,
    given that only numbers 1 through 9 can be used and each combination
    should be unique.

    Approach:
    - Use backtracking to explore combinations.
    - Start from 1 to 9, pick numbers recursively.
    - Stop when combination size is k and sum is n.
    - Prune recursion if sum exceeds n.

    Time Complexity: O(C(9, k)) - combinations of 9 digits taken k at a time.
    Space Complexity: O(k) - recursion stack and combination storage.
*/

#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(int k, int n, vector<vector<int>>& res, vector<int>& combi, int start) {
        if (n == 0 && combi.size() == k) {
            res.push_back(combi);
            return;
        }
        if (n < 0) return;

        for (int i = start; i <= 9; i++) {
            combi.push_back(i);
            backtrack(k, n - i, res, combi, i + 1);
            combi.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> combi;
        backtrack(k, n, res, combi, 1);
        return res;
    }
};

// Optional: test driver (commented out)
/*
#include <iostream>
int main() {
    Solution sol;
    int k = 3, n = 7;
    vector<vector<int>> ans = sol.combinationSum3(k, n);
    for (auto &v : ans) {
        for (int x : v) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
*/
