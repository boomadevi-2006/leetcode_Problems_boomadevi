/*
 * Problem: Minimum Path Sum
 * Link: https://leetcode.com/problems/minimum-path-sum/
 *
 * Approaches:
 * 1. Recursion + Memoization (Top-Down DP)
 * 2. Pure Recursion (No memoization, not efficient)
 *
 * Time Complexities:
 * - Memoization: O(m * n)
 * - Pure Recursion: O(2^(m + n))
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ------------------------------------
// ✅ Approach 1: Recursion + Memoization
// ------------------------------------
class SolutionMemoization {
public:
    int minPathSum(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& memo) {
        if (memo[r][c] != -1) return memo[r][c];

        if (r == 0 && c == 0)
            return memo[r][c] = grid[r][c];

        if (r == 0)
            return memo[r][c] = grid[r][c] + minPathSum(grid, r, c - 1, memo);

        if (c == 0)
            return memo[r][c] = grid[r][c] + minPathSum(grid, r - 1, c, memo);

        return memo[r][c] = grid[r][c] + min(
            minPathSum(grid, r - 1, c, memo),
            minPathSum(grid, r, c - 1, memo)
        );
    }

    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> memo(r, vector<int>(c, -1));
        return minPathSum(grid, r - 1, c - 1, memo);
    }
};

// ------------------------------------
// ⚠️ Approach 2: Pure Recursion (Inefficient)
// ------------------------------------
class SolutionRecursive {
public:
    int minPathSum(vector<vector<int>>& grid, int r, int c) {
        if (r == 0 && c == 0)
            return grid[r][c];

        if (r == 0)
            return grid[r][c] + minPathSum(grid, r, c - 1);

        if (c == 0)
            return grid[r][c] + minPathSum(grid, r - 1, c);

        return grid[r][c] + min(
            minPathSum(grid, r - 1, c),
            minPathSum(grid, r, c - 1)
        );
    }

    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        return minPathSum(grid, r - 1, c - 1);
    }
};

// ------------------------------------
// 🔧 Example Usage (Optional for Testing)
// ------------------------------------
/*
int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    SolutionMemoization sol1;
    SolutionRecursive sol2;

    cout << "Memoization Result: " << sol1.minPathSum(grid) << endl;
    cout << "Recursive Result:   " << sol2.minPathSum(grid) << endl;

    return 0;
}
*/

