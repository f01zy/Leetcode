#include <cmath>
#include <vector>

int sumFourDivisors(std::vector<int> &nums) {
  int r = 0;
  for (int i = 0; i < nums.size(); i++) {
    int num = nums[i];
    int c = 0;
    int s = 0;
    for (int j = 1; j <= static_cast<int>(std::sqrt(num)); j++) {
      if (num % j == 0) {
        int a = j;
        int b = num / j;
        c++;
        s += a;
        if (a != b) {
          c++;
          s += b;
        }
      }
    }
    if (c == 4) {
      r += s;
    }
  }
  return r;
}
