#include <algorithm>
#include <vector>
using namespace std;

int maxRotateFunction(vector<int> &nums) {
  int n = nums.size(), prev = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    prev += i * nums[i];
    sum += nums[i];
  }
  int ans = prev;
  for (int i = 1; i < n; i++) {
    prev = prev + sum - n * nums[n - i];
    ans = max(ans, prev);
  }
  return ans;
}
