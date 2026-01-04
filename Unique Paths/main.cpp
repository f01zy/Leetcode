#include <vector>

int getUniquePathsCount(std::vector<std::vector<int>> &cache, int x, int y) {
  if (cache[y][x] != -1) {
    return cache[y][x];
  }
  int m = cache.size();
  int n = cache[0].size();
  int c = 0;
  if (x == n - 1 && y == m - 1) {
    return 1;
  }
  if (x != n - 1) {
    c += getUniquePathsCount(cache, x + 1, y);
  }
  if (y != m - 1) {
    c += getUniquePathsCount(cache, x, y + 1);
  }
  cache[y][x] = c;
  return c;
}

int uniquePaths(int m, int n) {
  std::vector<std::vector<int>> cache(m, std::vector<int>(n, -1));
  return getUniquePathsCount(cache, 0, 0);
}
