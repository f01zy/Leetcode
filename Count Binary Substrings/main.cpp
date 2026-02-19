#include <string>

int charToNumber(char ch) { return ch - '0'; }

int countBinarySubstrings(std::string s) {
  if (s.size() == 1) {
    return 0;
  }
  int result{}, n = s.size();
  for (int i = 1; i < n; i++) {
    char num = s[i];
    char prev = s[i - 1];
    if (num == prev) {
      continue;
    }
    int l = i, r = i - 1;
    while (l < n && r >= 0) {
      if (s[l] == num && s[r] == prev) {
        result++;
      } else {
        break;
      }
      l++;
      r--;
    }
  }
  return result;
}
