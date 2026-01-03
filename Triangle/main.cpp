#include <vector>

int minimumTotal(std::vector<std::vector<int>> &triangle) {
  std::vector<int> cache = triangle[0];
  for (int i = 1; i < triangle.size(); i++) {
    std::vector<int> &currentLevel = triangle[i];
    std::vector<int> temp(i + 1);
    for (int j = 0; j < currentLevel.size(); j++) {
      int s = currentLevel[j];
      if (j == 0)
        s += cache[j];
      else if (j == currentLevel.size() - 1)
        s += cache[j - 1];
      else
        s += std::min(cache[j], cache[j - 1]);
      temp[j] = s;
    }
    cache = temp;
  }
  int result = cache[0];
  for (int i = 0; i < cache.size(); i++) {
    if (cache[i] < result) {
      result = cache[i];
    }
  }
  return result;
}
