#include <algorithm>
#include <vector>

int getMaxSubsequence(std::vector<int> nums) {
  int maxSubsequence = 1;
  int subsequence = 1;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i - 1] + 1 == nums[i]) {
      subsequence++;
    } else {
      subsequence = 1;
    }
    maxSubsequence = std::max(maxSubsequence, subsequence);
  }
  return maxSubsequence;
}

int maximizeSquareHoleArea(int n, int m, std::vector<int> &hBars, std::vector<int> &vBars) {
  std::sort(hBars.begin(), hBars.end());
  std::sort(vBars.begin(), vBars.end());
  int maxSubsequence = std::min(getMaxSubsequence(hBars), getMaxSubsequence(vBars));
  return (maxSubsequence + 1) * (maxSubsequence + 1);
}
