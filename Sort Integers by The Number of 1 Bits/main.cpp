#include <algorithm>
#include <vector>
using namespace std;

vector<int> sortByBits(vector<int> &arr) {
  sort(arr.begin(), arr.end(), [](int a, int b) {
    int ab = __builtin_popcount(a);
    int bb = __builtin_popcount(b);
    if (ab == bb) {
      return a < b;
    }
    return ab < bb;
  });
  return arr;
}
