#include <climits>
#include <vector>

int minimumPairRemoval(std::vector<int> &nums) {
  if (nums.size() <= 1) {
    return 0;
  }
  int r = 0;
  while (1) {
    int minimalPairSum = INT_MAX;
    int minimalPairIndex = 0;
    bool isOrdered = true;
    for (int i = 0; i < nums.size() - 1; i++) {
      int pairSum = nums[i] + nums[i + 1];
      if (nums[i] > nums[i + 1]) {
        isOrdered = false;
      }
      if (pairSum < minimalPairSum) {
        minimalPairSum = pairSum;
        minimalPairIndex = i;
      }
    }
    if (isOrdered) {
      break;
    }
    nums[minimalPairIndex] = minimalPairSum;
    nums.erase(nums.begin() + minimalPairIndex + 1);
    r++;
  }
  return r;
}
