#include <algorithm>
#include <climits>
#include <vector>

std::vector<std::vector<int>> minimumAbsDifference(std::vector<int> &arr) {
  std::vector<std::vector<int>> result;
  std::sort(arr.begin(), arr.end());
  int diff = INT_MAX;
  for (int i = 1; i < arr.size(); i++) {
    diff = std::min(diff, arr[i] - arr[i - 1]);
  }
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] - arr[i - 1] == diff) {
      result.push_back(std::vector<int>{arr[i - 1], arr[i]});
    }
  }
  return result;
}
