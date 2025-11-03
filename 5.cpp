class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int n = s.length();
        if (n < 2) {
            return s;
        }

        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));

        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        for (int L = 2; L <= n; ++L) {
            for (int i = 0; i <= n - L; ++i) {
                int j = i + L - 1;

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (L <= 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] && L > maxLength) {
                    maxLength = L;
                    start = i;
                }
            }
        }

        return s.substr(start, maxLength);
    }
};