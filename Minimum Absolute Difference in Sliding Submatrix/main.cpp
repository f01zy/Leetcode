#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int getDiff(vector<vector<int>> &grid, int i, int j, int k) {
  vector<int> nums;
  for (int p = 0; p < k; p++) {
    for (int l = 0; l < k; l++) {
      nums.push_back(grid[i + p][j + l]);
    }
  }
  sort(nums.begin(), nums.end());
  int diff = INT_MAX;
  for (int p = 1; p < nums.size(); p++) {
    int a = nums[p], b = nums[p - 1];
    if (a == b) { continue; }
    diff = min(diff, a - b);
  }
  if (diff == INT_MAX) { return 0; }
  return diff;
}

vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k) {
  int m = grid.size(), n = grid[0].size();
  vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i + k > m || j + k > n) { continue; }
      result[i][j] = getDiff(grid, i, j, k);
    }
  }
  return result;
}
