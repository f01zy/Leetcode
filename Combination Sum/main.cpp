#include <vector>
using namespace std;

vector<vector<int>> result;
vector<int> curr;
int currSum;

void process(vector<int> &candidates, int target, int start) {
  if (currSum == target) result.push_back(curr);
  if (currSum >= target) return;
  for (int i = start; i < candidates.size(); i++) {
    int temp = candidates[i];
    currSum += temp;
    curr.push_back(temp);
    process(candidates, target, i);
    currSum -= temp;
    curr.pop_back();
  }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  process(candidates, target, 0);
  return result;
}
