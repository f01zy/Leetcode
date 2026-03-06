#include <string>
using namespace std;

bool checkOnesSegment(string s) {
  if (s[0] != '1') {
    return false;
  }
  for (int i{}, j{}; i < s.size(); i++) {
    if (s[i] == '1' && j > 0) {
      return false;
    } else if (s[i] == '0') {
      j++;
    }
  }
  return true;
}
