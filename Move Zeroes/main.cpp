#include <vector>

void moveZeroes(std::vector<int> &nums) {
  int moves = 0;

  for (int i = 0; i < nums.size(); i++) {
    if (i == nums.size() - moves - 1) {
      break;
    }

    if (nums[i] == 0) {
      for (int j = i + 1; j < nums.size(); j++) {
        nums[j - 1] = nums[j];
      }

      nums[nums.size() - 1] = 0;
      i--;
      moves++;
    }
  }
}
