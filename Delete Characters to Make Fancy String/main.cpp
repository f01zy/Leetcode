#include <string>

std::string makeFancyString(std::string s) {
  std::string result{s[0]};
  for (int i = 1, j = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1]) {
      j++;
    } else {
      j = 1;
    }
    if (j <= 2) {
      result.push_back(s[i]);
    }
  }
  return result;
}
