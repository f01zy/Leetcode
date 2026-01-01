#include <cmath>
#include <string>

int titleToNumber(std::string columnTitle) {
  int r = 0, s = columnTitle.size() - 1;
  for (int i = 0; i <= s; i++) {
    int j = columnTitle[i] + 1 - 'A';
    i != s ? r += j * std::pow(26, s - i) : r += j;
  }
  return r;
}
