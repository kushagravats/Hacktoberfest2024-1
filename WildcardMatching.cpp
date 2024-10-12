#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int i = 1; i <= n; i++) {
            dp[i][0] = false;
        }

        for (int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j - 1] && p[j - 1] == '*';
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};

int main() {
    Solution solution;

    string s1 = "aa";
    string p1 = "a";
    if (solution.isMatch(s1, p1)) {
        cout << "Pattern matches string." << endl;
    } else {
        cout << "Pattern does not match string." << endl;
    }

    string s2 = "aa";
    string p2 = "*";
    if (solution.isMatch(s2, p2)) {
        cout << "Pattern matches string." << endl;
    } else {
        cout << "Pattern does not match string." << endl;
    }

    string s3 = "cb";
    string p3 = "?a";
    if (solution.isMatch(s3, p3)) {
        cout << "Pattern matches string." << endl;
    } else {
        cout << "Pattern does not match string." << endl;
    }

    return 0;
}
