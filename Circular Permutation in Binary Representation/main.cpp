// TODO

#include <vector>
using namespace std;

bool check(int i, int j) { return __builtin_popcount(i ^ j) == 1; }

bool process(vector<int> &result, vector<bool> &cache, int n, int i) {
  if (i == n) {
    return check(result[n - 1], result[0]);
  }
  for (int j = 0; j < n; j++) {
    if (!cache[j] && check(j, result[i - 1])) {
      cache[j] = true;
      result[i] = j;
      if (process(result, cache, n, i + 1)) {
        return true;
      }
      cache[j] = false;
      result[i] = 0;
    }
  }
  return false;
}

vector<int> circularPermutation(int n, int start) {
  n = 1 << n;
  vector<bool> cache(n, false);
  vector<int> result(n);
  result[0] = start;
  cache[start] = true;
  process(result, cache, n, 1);
  return result;
}
