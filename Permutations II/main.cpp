#include <set>
#include <vector>
using namespace std;

bool cache[8];
vector<int> curr;
set<vector<int>> uniquePermutations;

void process(vector<int> &nums) {
  bool isFinished = true;
  for (int i = 0; i < nums.size(); i++) {
    if (!cache[i]) {
      isFinished = false;
      cache[i] = true;
      curr.push_back(nums[i]);
      process(nums);
      curr.pop_back();
      cache[i] = false;
    }
  }
  if (isFinished) {
    uniquePermutations.insert(curr);
  }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
  process(nums);
  vector<vector<int>> result;
  for (auto it = uniquePermutations.begin(); it != uniquePermutations.end(); it++) {
    result.push_back(*it);
  }
  return result;
}
