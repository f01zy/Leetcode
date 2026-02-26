#include <string>
using namespace std;

int numSteps(string s) {
  int n = s.size(), count = 0;
  for (int i = n - 1; i >= 1; i--) {
    count++;
    if (s[i] == '0') {
      continue;
    }
    for (int j = i; j >= 0; j--) {
      if (!j) {
        count++;
        break;
      }
      if (s[j] == '0') {
        s[j] = '1';
        break;
      }
      s[j] = '0';
    }
    i++;
  }
  return count;
}
