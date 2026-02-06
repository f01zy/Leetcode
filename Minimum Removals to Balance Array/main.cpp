#include <algorithm>
#include <climits>
#include <vector>

int minRemoval(std::vector<int> &nums, int k) {
  int n = nums.size();
  if (n == 1) {
    return 0;
  }
  std::sort(nums.begin(), nums.end());
  int i = 0, j = 0, r = INT_MAX;
  while (j != n) {
    if (nums[j] <= static_cast<long long>(nums[i]) * k) {
      j++;
      r = std::min(r, n - j + i);
    } else {
      i++;
      j++;
    }
  }
  return r;
}
