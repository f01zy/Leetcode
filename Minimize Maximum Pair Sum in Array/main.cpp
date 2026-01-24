#include <algorithm>
#include <vector>

int minPairSum(std::vector<int> &nums) {
  std::sort(nums.begin(), nums.end());
  int n = nums.size();
  int maxPair = 0;
  for (int i = 0; i < n - i - 1; i++) {
    int pair = nums[i] + nums[n - i - 1];
    maxPair = std::max(maxPair, pair);
  }
  return maxPair;
}
