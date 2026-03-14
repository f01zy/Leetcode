#include <string>
#include <vector>
using namespace std;

string curr;
vector<string> strs;

void process(int n) {
  int m = curr.size();
  if (m >= n) {
    strs.push_back(curr);
    return;
  }
  for (int j = 0; j < 3; j++) {
    char ch = 'a' + j;
    if (m && curr[m - 1] == ch) {
      continue;
    }
    curr.push_back(ch);
    process(n);
    curr.pop_back();
  }
};

string getHappyString(int n, int k) {
  process(n);
  return k > strs.size() ? "" : strs[k - 1];
}
