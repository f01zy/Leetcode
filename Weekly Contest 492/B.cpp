#include <vector>
using namespace std;

int smallestBalancedIndex(vector<int> &nums) {
  int n = nums.size();
  vector<double> sum(n), product(n);
  for (int i = 0; i < n; i++) {
    sum[i] = i == 0 ? nums[i] : nums[i] + sum[i - 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    product[i] = i == n - 1 ? nums[i] : nums[i] * product[i + 1];
  }
  for (int i = 0; i < n; i++) {
    double a = i == 0 ? 0 : sum[i - 1];
    double b = i == n - 1 ? 1 : product[i + 1];
    if (a == b) {
      return i;
    }
  }
  return -1;
}
