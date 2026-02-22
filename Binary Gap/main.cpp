#include <algorithm>
using namespace std;

int binaryGap(int n) {
  int gap = 0, curr = 0, prev = 0;
  bool isFound = false;
  while (n) {
    if ((n & 1) && isFound) {
      gap = max(gap, curr - prev);
      prev = curr;
    } else if ((n & 1) && !isFound) {
      prev = curr;
      isFound = true;
    }
    curr++;
    n >>= 1;
  }
  return gap;
}
