#include <string>
#include <utility>
using namespace std;

bool checkStrings(string s1, string s2) {
  int n = s1.size();
  for (int i = 0; i < n; i++) {
    if (s1[i] == s2[i]) continue;
    bool isFound = false;
    for (int j = i + 2; j < n; j += 2) {
      if (s1[j] == s2[i]) {
        swap(s1[i], s1[j]);
        isFound = true;
        break;
      }
    }
    if (!isFound) return false;
  }
  return true;
}
