#include <algorithm>
#include <vector>

int maxArea(std::vector<int> &height) {
  int res = 0;
  int pl = 0;
  int pr = height.size() - 1;
  while (pl < pr) {
    int k = std::min(height[pl], height[pr]) * (pr - pl);
    if (k > res) {
      res = k;
    }
    if (height[pl] > height[pr]) {
      pr--;
    } else {
      pl++;
    }
  }
  return res;
}
