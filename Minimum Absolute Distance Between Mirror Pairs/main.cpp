#include <algorithm>
#include <climits>
#include <cstdlib>
#include <unordered_map>
#include <vector>
using namespace std;

int reverse(int num) {
  int reversed = 0;
  while (num > 0) {
    reversed = reversed * 10 + (num % 10);
    num /= 10;
  }
  return reversed;
}

int minMirrorPairDistance(vector<int> &nums) {
  unordered_map<int, int> cache;
  int ans = INT_MAX;
  for (int i = 0; i < nums.size(); i++) {
    int num = nums[i];
    if (cache.count(num)) ans = min(ans, abs(i - cache[num]));
    cache[reverse(num)] = i;
  }
  return ans == INT_MAX ? -1 : ans;
}
