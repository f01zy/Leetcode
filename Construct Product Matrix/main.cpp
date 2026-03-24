#include <vector>
using namespace std;

vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid) {
  int n = grid.size(), m = grid[0].size(), length = n * m;
  vector<int> nums(length);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      nums[i * m + j] = grid[i][j];
    }
  }
  vector<long long> prefix(length, 1);
  vector<long long> suffix(length, 1);
  for (int i = 1; i < length; i++) {
    prefix[i] = (prefix[i - 1] * nums[i - 1]) % 12345;
  }
  for (int i = length - 2; i >= 0; i--) {
    suffix[i] = (suffix[i + 1] * nums[i + 1]) % 12345;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int k = i * m + j;
      grid[i][j] = (prefix[k] * suffix[k]) % 12345;
    }
  }
  return grid;
}
