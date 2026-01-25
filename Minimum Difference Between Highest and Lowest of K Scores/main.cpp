#include <algorithm>
#include <climits>
#include <vector>

int minimumDifference(std::vector<int> &nums, int k) {
  if (k == 1) {
    return 0;
  }
  std::sort(nums.begin(), nums.end());
  int difference = INT_MAX;
  for (int i = 0; i + k - 1 < nums.size(); i++) {
    difference = std::min(difference, nums[i + k - 1] - nums[i]);
  }
  return difference;
}
