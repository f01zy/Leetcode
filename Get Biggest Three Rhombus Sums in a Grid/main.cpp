#include <queue>
#include <vector>
using namespace std;

int get_rhombus_sum(vector<vector<int>> &grid, int i, int j, int k) {
  if (k == 0) {
    return grid[i][j];
  }
  int sum = grid[i][j] + grid[i + k * 2][j];
  for (int l = 1; l <= k; l++) {
    sum += grid[i + l][j - l] + grid[i + l][j + l];
    if (l != k) {
      sum += grid[i + k * 2 - l][j - l] + grid[i + k * 2 - l][j + l];
    }
  }
  return sum;
}

vector<int> getBiggestThree(vector<vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  priority_queue<int> queue;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; i + k * 2 < m && j - k >= 0 && j + k < n; k++) {
        int sum = get_rhombus_sum(grid, i, j, k);
        queue.push(sum);
      }
    }
  }
  vector<int> result;
  while (!queue.empty()) {
    int sum = queue.top();
    queue.pop();
    if (!result.empty() && result[result.size() - 1] == sum) {
      continue;
    }
    result.push_back(sum);
    if (result.size() >= 3) {
      break;
    }
  }
  return result;
}
