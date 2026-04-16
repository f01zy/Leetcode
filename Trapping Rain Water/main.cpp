#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int trap(vector<int> &height) {
  int ans = 0;
  stack<int> s;
  for (int i = 0; i < height.size(); i++) {
    int curr = height[i];
    int maxHeight = 0;
    if (!curr) continue;
    while (!s.empty() && curr > height[s.top()]) {
      int mid = s.top();
      s.pop();
      if (s.empty()) break;
      int left = s.top();
      int h = min(height[left], curr) - height[mid];
      int w = i - left - 1;
      ans += h * w;
    }
    s.push(i);
  }
  return ans;
}
