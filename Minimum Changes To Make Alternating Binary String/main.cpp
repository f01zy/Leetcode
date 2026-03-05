#include <algorithm>
#include <string>
using namespace std;

int getMinOperations(string &s, char prev) {
  int result{};
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == prev) {
      result++;
    }
    prev = prev == '0' ? '1' : '0';
  }
  return result;
}

int minOperations(string s) {
  return min(getMinOperations(s, '0'), getMinOperations(s, '1'));
}
