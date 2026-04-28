#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int minOperations(vector<vector<int>> &grid, int x) {
  vector<int> nums;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      nums.push_back(grid[i][j]);
    }
  }
  sort(nums.begin(), nums.end());
  int n = nums.size();
  for (int i = 1; i < n; i++) {
    if (nums[i] % x != nums[i - 1] % x) return -1;
  }
  int target = nums[n / 2];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += abs(target - nums[i]) / x;
  }
  return ans;
}
