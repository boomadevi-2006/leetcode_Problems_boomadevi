#include <vector>
using namespace std;

/*
 * Unique Paths Problem Solutions
 * 
 * Approaches included:
 * 1. Dynamic Programming (Tabulation)
 *    - Use a 2D dp array where dp[i][j] represents the number of unique paths to reach cell (i, j).
 *    - Initialize first row and first column to 1 (only one way to reach cells in first row/column).
 *    - For other cells, dp[i][j] = dp[i-1][j] + dp[i][j-1].
 *    - Time Complexity: O(m*n)
 *    - Space Complexity: O(m*n)
 * 
 * 2. Memoization (Top-Down DP)
 *    - Use recursion with memoization to avoid repeated calculations.
 *    - Base cases: If we reach first row or first column, only 1 path.
 *    - For other positions, number of paths = sum of paths from above and left cells.
 *    - Time Complexity: O(m*n)
 *    - Space Complexity: O(m*n) due to recursion stack and memo table.
 * 
 * 3. Naive Recursion (Exponential)
 *    - Simple recursive solution without memoization.
 *    - Base case: If m == 1 or n == 1, return 1.
 *    - Recursive case: sum of unique paths from cell above and cell left.
 *    - Time Complexity: Exponential, highly inefficient for large inputs.
 *    - Space Complexity: O(m+n) due to recursion stack.
 */

//////////////////////////////////////
// 1. Dynamic Programming (Tabulation)
//////////////////////////////////////
class SolutionDP {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

//////////////////////////////////////
// 2. Memoization (Top-Down DP)
//////////////////////////////////////
class SolutionMemo {
    vector<vector<int>> memo;
public:
    int uniquePaths(int m, int n) {
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        return helper(m - 1, n - 1);
    }

private:
    int helper(int m, int n) {
        if (m == 0 || n == 0) return 1;
        if (memo[m][n] != -1) return memo[m][n];
        return memo[m][n] = helper(m - 1, n) + helper(m, n - 1);
    }
};

//////////////////////////////////////
// 3. Naive Recursion (Exponential)
//////////////////////////////////////
class SolutionRecursion {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};
