#include <vector>

int getMinPathSum(std::vector<std::vector<int>> &grid, std::vector<std::vector<int>> &cache, int x, int y) {
  int m = grid[0].size();
  int n = grid.size();

  if (x == m - 1 && y == n - 1)
    return grid[y][x];
  if (cache[y][x] != -1)
    return cache[y][x];

  int sum = grid[y][x];
  if (x == m - 1)
    sum += getMinPathSum(grid, cache, x, y + 1);
  else if (y == n - 1)
    sum += getMinPathSum(grid, cache, x + 1, y);
  else
    sum += std::min(getMinPathSum(grid, cache, x, y + 1), getMinPathSum(grid, cache, x + 1, y));

  cache[y][x] = sum;
  return sum;
}

int minPathSum(std::vector<std::vector<int>> &grid) {
  int m = grid[0].size();
  int n = grid.size();
  std::vector<std::vector<int>> cache(n, std::vector<int>(m, -1));
  return getMinPathSum(grid, cache, 0, 0);
}
