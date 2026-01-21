#include <vector>

std::vector<int> minBitwiseArray(std::vector<int> &nums) {
  int n = nums.size();
  std::vector<int> ans(n, -1);
  for (int i = 0; i < n; i++) {
    int num = nums[i];
    if (num % 2 == 0) {
      continue;
    }
    for (int j = 1; j < 32; j++) {
      if (((num >> j) & 1) == 0) {
        num ^= (1 << (j - 1));
        break;
      }
    }
    ans[i] = num;
  }
  return ans;
}
