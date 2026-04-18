#include <cstdlib>

int reverse(int num) {
  int ans = 0;
  while (num) {
    ans = ans * 10 + (num % 10);
    num /= 10;
  }
  return ans;
}

int mirrorDistance(int n) { return abs(n - reverse(n)); }
