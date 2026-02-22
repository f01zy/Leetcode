#include <vector>
using namespace std;

bool cache[6];
vector<int> curr;
vector<vector<int>> result;

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
    result.push_back(curr);
  }
}

vector<vector<int>> permute(vector<int> &nums) {
  process(nums);
  return result;
}
