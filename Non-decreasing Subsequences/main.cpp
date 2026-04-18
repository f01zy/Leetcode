#include <set>
#include <vector>
using namespace std;

set<vector<int>> ans;
vector<int> curr;

void process(vector<int> &nums, int i) {
  if (i >= nums.size()) {
    if (curr.size() >= 2) ans.emplace(curr);
    return;
  }
  process(nums, i + 1);
  if (!curr.size() || nums[i] >= curr[curr.size() - 1]) {
    curr.push_back(nums[i]);
    process(nums, i + 1);
    curr.pop_back();
  }
}

vector<vector<int>> findSubsequences(vector<int> &nums) {
  process(nums, 0);
  vector<vector<int>> result;
  for (auto iter = ans.begin(); iter != ans.end(); iter++) {
    result.push_back(*iter);
  }
  return result;
}
