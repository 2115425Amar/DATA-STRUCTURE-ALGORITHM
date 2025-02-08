#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int solve(string text1, string text2, int i, int j, vector<vector<int>>& dp) {
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if (text1[i] == text2[j]) {
            ans = 1 + solve(text1, text2, i + 1, j + 1, dp);
        } else {
            ans = max(solve(text1, text2, i, j + 1, dp), solve(text1, text2, i + 1, j, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(text1, text2, 0, 0, dp);
    }
};

int main() {
    Solution sol;
    string text1 = "abcde";
    string text2 = "ace";
    cout << "Length of Longest Common Subsequence: " << sol.longestCommonSubsequence(text1, text2) << endl;
    return 0;
}