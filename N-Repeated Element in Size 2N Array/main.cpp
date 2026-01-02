#include <vector>

int repeatedNTimes(std::vector<int> &nums) {
  for (int i = 0; i < nums.size() - 1; i++) {
    for (int j = nums.size() - 1; j > i; j--) {
      if (nums[i] == nums[j]) {
        return nums[i];
      }
    }
  }
  return 0;
}
