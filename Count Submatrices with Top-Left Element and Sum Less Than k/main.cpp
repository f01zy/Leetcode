#include <vector>
using namespace std;

int countSubmatrices(vector<vector<int>> &grid, int k) {
  int m = grid.size(), n = grid[0].size();
  int prefix[m][n];
  int count = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int sum = grid[i][j];
      if (i > 0) { sum += prefix[i - 1][j]; }
      if (j > 0) { sum += prefix[i][j - 1]; }
      if (i > 0 && j > 0) { sum -= prefix[i - 1][j - 1]; }
      prefix[i][j] = sum;
      if (sum <= k) { count++; }
    }
  }
  return count;
}
