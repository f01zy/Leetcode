#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int numberOfSubmatrices(vector<vector<char>> &grid) {
  int m = grid.size(), n = grid[0].size(), count = 0;
  int k = INT_MAX, l = INT_MAX;
  int prefix[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      char ch = grid[i][j];
      int num = 0;
      if (ch == 'X') {
        k = min(k, i);
        l = min(l, j);
        num = 1;
      } else if (ch == 'Y') {
        num = -1;
      }
      int sum = num;
      if (i > 0) sum += prefix[i - 1][j];
      if (j > 0) sum += prefix[i][j - 1];
      if (i > 0 && j > 0) sum -= prefix[i - 1][j - 1];
      prefix[i][j] = sum;
      if (sum == 0 && i >= k && j >= l) count++;
    }
  }
  return count;
}
