// TODO

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
  vector<long long> prefix(length);
  vector<long long> suffix(length);
  for (int i = 0; i < length; i++) {
    prefix[i] = i == 0 ? nums[i] : (nums[i] * prefix[i - 1]) % 12345;
    suffix[length - i - 1] = i == 0 ? nums[length - i - 1] : (nums[length - i - 1] * suffix[length - i]) % 12345;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int k = i * m + j;
      grid[i][j] = k == 0 ? suffix[1] : k == length - 1 ? prefix[k - 1] : prefix[k - 1] * suffix[k + 1];
    }
  }
  return grid;
}
