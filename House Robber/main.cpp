#include <algorithm>
#include <vector>
using namespace std;

int process(vector<int> nums, vector<int> &dp, int i) {
  if (dp[i] != -1) return dp[i];
  int curr = max(process(nums, dp, i - 2) + nums[i], process(nums, dp, i - 1));
  dp[i] = curr;
  return curr;
}

int rob(vector<int> &nums) {
  if (nums.size() == 1) return nums[0];
  if (nums.size() == 2) return max(nums[0], nums[1]);
  vector<int> dp(nums.size(), -1);
  dp[0] = nums[0];
  dp[1] = max(nums[0], nums[1]);
  return process(nums, dp, nums.size() - 1);
}
