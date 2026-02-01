#include <algorithm>
#include <vector>

int minimumCost(std::vector<int> &nums) {
  int a = nums[0];
  std::sort(nums.begin(), nums.end());
  if (nums[0] == a || nums[1] == a || nums[2] == a) {
    return nums[0] + nums[1] + nums[2];
  } else {
    return nums[0] + nums[1] + a;
  }
  return -1;
}
