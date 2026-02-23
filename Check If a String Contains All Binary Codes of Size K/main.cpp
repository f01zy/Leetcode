#include <cmath>
#include <string>
#include <unordered_map>
using namespace std;

bool hasAllCodes(string s, int k) {
  int n = s.size();
  int i = 0 - k + 1, j = 0, num = 0;
  int sequences = pow(2, k), count = 0;
  unordered_map<int, bool> cache;

  while (j < n) {
    num &= ~(1 << (k - 1));
    num <<= 1;
    num |= (s[j] - '0');
    if (i >= 0 && num >= sequences) {
      return false;
    }
    if (i >= 0 && !cache[num]) {
      count++;
      cache[num] = true;
    }
    i++;
    j++;
  }

  if (count != sequences) {
    return false;
  }
  return true;
}
