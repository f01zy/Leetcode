#include <string>
#include <vector>
using namespace std;

string findDifferentBinaryString(vector<string> &nums) {
  const int n = nums[0].size();
  const int c = 2 << (n - 1);
  vector<bool> cache(c, false);
  for (const string &s : nums) {
    int num = 0;
    for (int i = 0; i < n; i++) {
      num |= ((s[n - i - 1] - '0') << i);
    }
    cache[num] = true;
  }
  for (int i = 0; i <= c; i++) {
    if (!cache[i]) {
      string num{};
      for (int j = 0; j < n; j++) {
        char ch = '0';
        if (i) {
          ch = '0' + (i & 1);
          i >>= 1;
        }
        num = ch + num;
      }
      return num;
    }
  }
  return nullptr;
}
