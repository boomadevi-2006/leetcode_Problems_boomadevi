/*
 * Problem: Edit Distance (Levenshtein Distance)
 * Link: https://leetcode.com/problems/edit-distance/
 *
 * Approaches:
 * 1. Top-Down DP (Memoization)
 * 2. Pure Recursion (Exponential)
 *
 * Time Complexities:
 * - Memoization: O(m * n)
 * - Pure Recursion: O(3^(m + n))
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// --------------------------------------------------------------------
// ✅ Approach 1: Top-Down DP (Memoization)
// --------------------------------------------------------------------
class EditDistanceMemoized {
public:
    int minDistance(string &s, string &t, int i, int j, vector<vector<int>> &memo) {
        if (j < 0) return i + 1;
        if (i < 0) return j + 1;

        if (memo[i][j] != -1) return memo[i][j];

        if (s[i] == t[j]) {
            return memo[i][j] = minDistance(s, t, i - 1, j - 1, memo);
        }

        return memo[i][j] = 1 + min({
            minDistance(s, t, i - 1, j, memo),     // Delete
            minDistance(s, t, i, j - 1, memo),     // Insert
            minDistance(s, t, i - 1, j - 1, memo)  // Replace
        });
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return minDistance(word1, word2, m - 1, n - 1, memo);
    }
};

// --------------------------------------------------------------------
// ⚠️ Approach 2: Pure Recursion (No Memoization)
// --------------------------------------------------------------------
class EditDistanceRecursive {
public:
    int minDistance(string &s, string &t, int i, int j) {
        if (j < 0) return i + 1;
        if (i < 0) return j + 1;

        if (s[i] == t[j]) {
            return minDistance(s, t, i - 1, j - 1);
        }

        return 1 + min({
            minDistance(s, t, i - 1, j),     // Delete
            minDistance(s, t, i, j - 1),     // Insert
            minDistance(s, t, i - 1, j - 1)  // Replace
        });
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        return minDistance(word1, word2, m - 1, n - 1);
    }
};

// --------------------------------------------------------------------
// 🔧 Example Usage (Commented Out)
// --------------------------------------------------------------------
/*
int main() {
    string w1 = "intention", w2 = "execution";

    EditDistanceMemoized memoSol;
    EditDistanceRecursive recSol;

    cout << "Memoized DP: " << memoSol.minDistance(w1, w2) << endl;
    cout << "Pure Recursion: " << recSol.minDistance(w1, w2) << endl;

    return 0;
}
*/
