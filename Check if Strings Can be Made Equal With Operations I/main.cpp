#include <string>
using namespace std;

bool canBeEqual(string s1, string s2) {
  bool cache[4]{false};
  for (int i = 0; i < 4; i++) {
    if (s1[i] != s2[i]) {
      if (cache[i]) { continue; }
      if (i > 2 || (s1[i] != s2[i + 2]) || (s2[i] != s1[i + 2])) { return false; }
      cache[i] = cache[i + 2] = true;
    }
  }
  return true;
}
