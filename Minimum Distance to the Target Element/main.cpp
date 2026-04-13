#include <climits>
#include <cstdlib>
#include <vector>
using namespace std;

int getMinDistance(vector<int> &nums, int target, int start) {
  int n = nums.size(), i = start, j = start, ans = INT_MAX;
  while (i >= 0 || j < n) {
    if (i >= 0 && nums[i] == target) ans = min(ans, abs(i - start));
    if (j < n && nums[j] == target) ans = min(ans, abs(j - start));
    i--;
    j++;
  }
  return ans;
}
