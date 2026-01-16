#include <algorithm>
#include <cstdlib>
#include <vector>

int maximizeSquareArea(int m, int n, std::vector<int> &hFences, std::vector<int> &vFences) {
  hFences.push_back(1);
  hFences.push_back(m);
  vFences.push_back(1);
  vFences.push_back(n);
  std::vector<int> h, v;
  for (int i = 0; i < hFences.size(); i++) {
    for (int j = 0; j < hFences.size(); j++) {
      if (i == j) {
        continue;
      }
      h.push_back(std::abs(hFences[i] - hFences[j]));
    }
  }
  for (int i = 0; i < vFences.size(); i++) {
    for (int j = 0; j < vFences.size(); j++) {
      if (i == j) {
        continue;
      }
      v.push_back(std::abs(vFences[i] - vFences[j]));
    }
  }
  std::sort(h.begin(), h.end());
  std::sort(v.begin(), v.end());
  int i = h.size() - 1, j = v.size() - 1;
  while (i >= 0 && j >= 0) {
    if (h[i] == v[j]) {
      long long area = static_cast<long long>(h[i]) * v[j];
      if (area > 1000000007) {
        return area % 1000000007;
      }
      return area;
    } else if (h[i] < v[j]) {
      j--;
    } else {
      i--;
    }
  }
  return -1;
}
