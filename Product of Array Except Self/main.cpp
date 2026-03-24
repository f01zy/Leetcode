#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums) {
  int n = nums.size();
  vector<int> prefix(n);
  vector<int> suffix(n);
  for (int i = 0; i < n; i++) {
    prefix[i] = i == 0 ? nums[i] : nums[i] * prefix[i - 1];
    suffix[n - i - 1] = i == 0 ? nums[n - i - 1] : nums[n - i - 1] * suffix[n - i];
  }
  vector<int> result;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      result[i] = suffix[1];
    } else if (i == n - 1) {
      result[i] = prefix[n - 2];
    } else {
      result[i] = prefix[i - 1] * suffix[i + 1];
    }
  }
  return result;
}
