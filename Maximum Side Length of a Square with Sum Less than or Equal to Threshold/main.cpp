#include <algorithm>
#include <vector>

int maxSideLength(std::vector<std::vector<int>> &mat, int threshold) {
  int m = mat.size();
  int n = mat[0].size();
  int result = 0;
  std::vector<std::vector<int>> prefix(m, std::vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      prefix[i][j] = mat[i][j];
      if (i > 0) {
        prefix[i][j] += prefix[i - 1][j];
      }
      if (j > 0) {
        prefix[i][j] += prefix[i][j - 1];
      }
      if (i > 0 && j > 0) {
        prefix[i][j] -= prefix[i - 1][j - 1];
      }
      for (int k = std::min(i, j) + 1; k > 0; k--) {
        int p = i - k + 1;
        int b = j - k + 1;
        int total = prefix[i][j];
        int top = p - 1 >= 0 ? prefix[p - 1][j] : 0;
        int left = b - 1 >= 0 ? prefix[i][b - 1] : 0;
        int overlap = p - 1 >= 0 && b - 1 >= 0 ? prefix[p - 1][b - 1] : 0;
        int sum = total - top - left + overlap;
        if (sum <= threshold) {
          result = std::max(result, k);
          break;
        }
      }
    }
  }
  return result;
}
