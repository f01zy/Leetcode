#include <vector>

std::vector<int> minBitwiseArray(std::vector<int> &nums) {
  int n = nums.size();
  std::vector<int> ans(n, -1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= nums[i]; j++) {
      if ((j | (j + 1)) == nums[i]) {
        ans[i] = j;
        break;
      }
    }
  }
  return ans;
}
