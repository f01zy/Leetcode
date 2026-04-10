#include <algorithm>
#include <climits>
#include <cstdlib>
#include <unordered_map>
#include <vector>
using namespace std;

int minimumDistance(vector<int> &nums) {
  unordered_map<int, vector<int>> cache;
  for (int i = 0; i < nums.size(); i++) {
    cache[nums[i]].push_back(i);
  }
  int ans = INT_MAX;
  for (auto iter = cache.begin(); iter != cache.end(); iter++) {
    vector<int> &temp = iter->second;
    if (temp.size() < 3) continue;
    sort(temp.begin(), temp.end());
    for (int i = 2; i < temp.size(); i++) {
      ans = min(ans, abs(temp[i - 2] - temp[i - 1]) + abs(temp[i - 1] - temp[i]) + abs(temp[i] - temp[i - 2]));
    }
  }
  return ans == INT_MAX ? -1 : ans;
}
