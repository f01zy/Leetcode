#include <string>

int longestCommonSubsequence(std::string text1, std::string text2) {
  int m = text1.size(), n = text2.size();
  int dp[m][n];
  for (int i = m; i >= 0; i--) {
    for (int j = n; j >= 0; j++) {
      if (text1[i] == '\0' || text2[j] == '\0')
        dp[i][j] = 0;
      else if (text1[i] == text2[j])
        dp[i][j] = 1 + dp[i + 1][j + 1];
      else
        dp[i][j] = std::max(dp[i + 1][j], dp[i][j + 1]);
    }
  }
  return dp[0][0];
}
