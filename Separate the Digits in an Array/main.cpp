#include <vector>
using namespace std;

vector<int> separateDigits(vector<int> &nums) {
  vector<int> ans;
  for (int i = 0; i < nums.size(); i++) {
    int num = nums[i];
    vector<int> temp;
    while (num) {
      temp.push_back(num % 10);
      num /= 10;
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
      ans.push_back(temp[i]);
    }
  }
  return ans;
}
