#include <vector>
using namespace std;

/*
 * Unique Paths Problem Solutions
 * 
 * Three approaches included:
 * 1. Dynamic Programming (Tabulation)
 * 2. Memoization (Top-Down)
 * 3. Naive Recursion (Exponential time)
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
