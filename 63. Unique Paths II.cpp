/*
 * 63. Unique Paths II
 *
 * Problem:
 * Given a grid with obstacles (1) and empty spaces (0), find the number of unique paths
 * from top-left to bottom-right moving only right or down.
 *
 * Contains three approaches:
 * 1) Bottom-up DP (Tabulation)
 * 2) Top-down DP with Memoization
 * 3) Pure Recursion (not recommended for large inputs)
 */

#include <vector>
using namespace std;

class Solution {
public:
    // ----------- Bottom-up DP (Tabulation) -----------
    int uniquePathsWithObstaclesBottomUp(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        if (grid[0][0] == 1 || grid[r-1][c-1] == 1)
            return 0;

        vector<vector<int>> dp(r, vector<int>(c, 0));
        dp[0][0] = 1;

        for (int i = 1; i < r; i++) {
            dp[i][0] = (grid[i][0] == 0 && dp[i-1][0] == 1) ? 1 : 0;
        }

        for (int j = 1; j < c; j++) {
            dp[0][j] = (grid[0][j] == 0 && dp[0][j-1] == 1) ? 1 : 0;
        }

        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                if (grid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[r-1][c-1];
    }

    // ----------- Top-down DP with Memoization -----------
    int uniquePathsWithObstaclesTopDown(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& memo) {
        if (r < 0 || c < 0) return 0;
        if (grid[r][c] == 1) return 0;
        if (r == 0 && c == 0) return 1;
        if (memo[r][c] != -1) return memo[r][c];

        return memo[r][c] = uniquePathsWithObstaclesTopDown(grid, r - 1, c, memo) + uniquePathsWithObstaclesTopDown(grid, r, c - 1, memo);
    }

    int uniquePathsWithObstaclesTopDown(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> memo(r, vector<int>(c, -1));
        return uniquePathsWithObstaclesTopDown(grid, r - 1, c - 1, memo);
    }

    // ----------- Pure Recursion (No memoization) -----------
    int uniquePathsWithObstaclesRecursive(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0) return 0;
        if (grid[r][c] == 1) return 0;
        if (r == 0 && c == 0) return 1;
        return uniquePathsWithObstaclesRecursive(grid, r - 1, c) + uniquePathsWithObstaclesRecursive(grid, r, c - 1);
    }

    int uniquePathsWithObstaclesRecursive(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        return uniquePathsWithObstaclesRecursive(grid, r - 1, c - 1);
    }
};
