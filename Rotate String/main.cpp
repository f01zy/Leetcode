#include <string>
using namespace std;

bool rotateString(string s, string goal) {
  if (s.size() != goal.size()) return false;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    bool isEqual = true;
    for (int j = 0; j < n; j++) {
      if (s[(j - i + n) % n] != goal[j]) {
        isEqual = false;
        break;
      }
    }
    if (isEqual) return true;
  }
  return false;
}
