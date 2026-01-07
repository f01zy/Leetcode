#include <vector>

bool checkCanJupm(std::vector<int> &nums, std::vector<int> &dp, int x) {
  int distance = nums[x];
  if (x + distance >= nums.size() - 1) {
    return 1;
  }
  if (dp[x] != -1) {
    return dp[x];
  }
  for (int i = 1; i <= distance; i++) {
    if (checkCanJupm(nums, dp, x + i)) {
      return 1;
    }
  }
  dp[x] = 0;
  return 0;
}

bool canJump(std::vector<int> &nums) {
  std::vector<int> dp(nums.size(), -1);
  return checkCanJupm(nums, dp, 0);
}
