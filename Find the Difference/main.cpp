#include <string>

char findTheDifference(std::string s, std::string t) {
  int a = 0, b = 0, i = 0, n = s.size(), m = t.size();
  while (i < n || i < m) {
    if (i != n) {
      a += static_cast<int>(s[i]);
    }
    if (i != m) {
      b += static_cast<int>(t[i]);
    }
    i++;
  }
  return static_cast<char>(std::abs(a - b));
}
