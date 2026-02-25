#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums) {
  int n = nums.size();
  vector<int> prefix(n);
  for (int i = 0; i < n; i++) {
    if (nums[i] >= target) {
      return 1;
    }
    prefix[i] = i == 0 ? nums[i] : nums[i] + prefix[i - 1];
  }
  if (prefix[n - 1] < target) {
    return 0;
  }
  int i = 0, j = 0, result = INT_MAX;
  while (j < n) {
    int sum = prefix[j];
    if (i - 1 >= 0) {
      sum -= prefix[i - 1];
    }
    if (sum < target) {
      j++;
    } else {
      result = min(result, j - i + 1);
      i++;
    }
  }
  return result;
}
