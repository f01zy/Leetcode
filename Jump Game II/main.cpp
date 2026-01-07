#include <vector>

int getMinJumpsCount(std::vector<int> &nums, std::vector<int> &dp, int x) {
  int distance = nums[x];
  if (x + distance >= nums.size() - 1) {
    return 1;
  }
  if (dp[x] != -1) {
    return dp[x];
  }
  int minJumpsCount = nums.size();
  for (int i = 1; i <= distance; i++) {
    minJumpsCount = std::min(minJumpsCount, getMinJumpsCount(nums, dp, x + i));
  }
  minJumpsCount++;
  dp[x] = minJumpsCount;
  return minJumpsCount;
}

int jump(std::vector<int> &nums) {
  if (nums.size() <= 1) {
    return 0;
  }
  std::vector<int> dp(nums.size(), -1);
  return getMinJumpsCount(nums, dp, 0);
}
