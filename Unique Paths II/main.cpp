#include <vector>
using namespace std;

int dp[100][100]{0};

int process(vector<vector<int>> &obstacleGrid, int i, int j) {
  if (obstacleGrid[i][j]) {
    return 0;
  }
  if (dp[i][j]) {
    return dp[i][j];
  }
  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();
  if (i == m - 1 && j == n - 1) {
    return 1;
  }
  int paths = 0;
  if (i != m - 1) {
    paths += process(obstacleGrid, i + 1, j);
  }
  if (j != n - 1) {
    paths += process(obstacleGrid, i, j + 1);
  }
  dp[i][j] = paths;
  return paths;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
  return process(obstacleGrid, 0, 0);
}
