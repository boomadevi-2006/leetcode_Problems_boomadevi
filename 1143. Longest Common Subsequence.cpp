/*
 * Problem: Longest Common Subsequence
 * Link: https://leetcode.com/problems/longest-common-subsequence/
 *
 * Approaches:
 * 1. Space-Optimized Dynamic Programming (1D DP)
 * 2. Top-Down DP with Memoization
 * 3. Pure Recursion (No Memoization)
 * 4. Bottom-Up DP (Tabulation)
 *
 * Time Complexities:
 * - 1D DP: O(m * n), Space: O(n)
 * - Memoization: O(m * n), Space: O(m * n)
 * - Pure Recursion: O(2^(m + n))
 * - Bottom-Up Tabulation: O(m * n), Space: O(m * n)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// --------------------------------------------------------------------
// ✅ Approach 1: Space-Optimized DP (1D)
// --------------------------------------------------------------------
class LCS_SpaceOptimized {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text1.length(), 0);
        int longest = 0;

        for (char c : text2) {
            int curLength = 0;
            for (int i = 0; i < dp.size(); i++) {
                if (curLength < dp[i]) {
                    curLength = dp[i];
                } else if (c == text1[i]) {
                    dp[i] = curLength + 1;
                    longest = max(longest, dp[i]);
                }
            }
        }

        return longest;
    }
};

// --------------------------------------------------------------------
// ✅ Approach 2: Recursion + Memoization (Top-Down DP)
// --------------------------------------------------------------------
class LCS_Memoization {
public:
    int lcsHelper(string &s, string &t, int i, int j, vector<vector<int>>& memo) {
        if (i < 0 || j < 0) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        if (s[i] == t[j])
            return memo[i][j] = 1 + lcsHelper(s, t, i - 1, j - 1, memo);
        return memo[i][j] = max(lcsHelper(s, t, i - 1, j, memo), lcsHelper(s, t, i, j - 1, memo));
    }

    int longestCommonSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return lcsHelper(s, t, m - 1, n - 1, memo);
    }
};

// --------------------------------------------------------------------
// ⚠️ Approach 3: Pure Recursion (No Memoization)
// --------------------------------------------------------------------
class LCS_Recursive {
public:
    int lcsHelper(string &s, string &t, int i, int j) {
        if (i < 0 || j < 0) return 0;
        if (s[i] == t[j])
            return 1 + lcsHelper(s, t, i - 1, j - 1);
        return max(lcsHelper(s, t, i - 1, j), lcsHelper(s, t, i, j - 1));
    }

    int longestCommonSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        return lcsHelper(s, t, m - 1, n - 1);
    }
};

// --------------------------------------------------------------------
// ✅ Approach 4: Bottom-Up DP (Tabulation)
// --------------------------------------------------------------------
class LCS_Tabulation {
public:
    int longestCommonSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};

// --------------------------------------------------------------------
// 🔧 Example Usage (Commented Out)
// --------------------------------------------------------------------
/*
int main() {
    string s1 = "abcde";
    string s2 = "ace";

    LCS_SpaceOptimized sol1;
    LCS_Memoization sol2;
    LCS_Recursive sol3;
    LCS_Tabulation sol4;

    cout << "Space-Optimized DP: " << sol1.longestCommonSubsequence(s1, s2) << endl;
    cout << "Memoization:        " << sol2.longestCommonSubsequence(s1, s2) << endl;
    cout << "Pure Recursion:     " << sol3.longestCommonSubsequence(s1, s2) << endl;
    cout << "Bottom-Up DP:       " << sol4.longestCommonSubsequence(s1, s2) << endl;

    return 0;
}
*/
