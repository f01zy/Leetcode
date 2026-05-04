#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int dp[2500][2500]{-1};

int process(vector<int> &nums, int i, int prev_index) {
  if (i == nums.size()) return 0;
  if (dp[i][prev_index + 1] != -1) return dp[i][prev_index + 1];
  int ans = process(nums, i + 1, prev_index);
  if (prev_index == -1 || nums[prev_index] < nums[i]) ans = max(ans, process(nums, i + 1, i) + 1);
  return dp[i][prev_index + 1] = ans;
}

int lengthOfLIS(vector<int> &nums) {
  memset(dp, -1, sizeof(dp));
  return process(nums, 0, -1);
}
