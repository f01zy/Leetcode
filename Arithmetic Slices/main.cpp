#include <vector>
using namespace std;

bool isArithmetic(vector<int> &nums, int left, int right) {
  int diff = nums[left + 1] - nums[left];
  for (int i = left + 1; i < right; i++) {
    if (nums[i + 1] - nums[i] != diff) return false;
  }
  return true;
}

int numberOfArithmeticSlices(vector<int> &nums) {
  int n = nums.size(), result = 0;
  if (n < 3) return 0;
  for (int i = 0; i < n; i++) {
    int left = i, right = left + 2;
    while (right < n) {
      if (isArithmetic(nums, left, right++)) result++;
    }
  }
  return result;
}
