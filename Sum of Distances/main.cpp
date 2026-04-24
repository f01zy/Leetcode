#include <cstdlib>
#include <unordered_map>
#include <vector>
using namespace std;

vector<long long> distance(vector<int> &nums) {
  int n = nums.size();
  vector<long long> ans;
  unordered_map<int, vector<int>> pos;
  for (int i = 0; i < n; i++) {
    pos[nums[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    long long curr = 0;
    if (pos.count(nums[i])) {
      for (const int &j : pos[i]) {
        curr += abs(i - j);
      }
    }
    ans.push_back(curr);
  }
  return ans;
}
