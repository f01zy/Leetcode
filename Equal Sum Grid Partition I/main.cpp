#include <vector>
using namespace std;

bool canPartitionGrid(vector<vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size(), l = m * n;
  vector<int> h(l), v(l);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      h[i * n + j] = grid[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      v[i * m + j] = grid[j][i];
    }
  }
  vector<long long> hp(l), vp(l);
  hp[0] = vp[0] = grid[0][0];
  for (int i = 1; i < l; i++) {
    hp[i] = hp[i - 1] + h[i];
    vp[i] = vp[i - 1] + v[i];
  }
  for (int i = n - 1; i < l; i += n) {
    long long a = hp[i];
    long long b = hp[l - 1] - a;
    if (a == b) { return true; }
  }
  for (int i = m - 1; i < l; i += m) {
    long long a = vp[i];
    long long b = vp[l - 1] - a;
    if (a == b) { return true; }
  }
  return false;
}
