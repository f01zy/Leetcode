#include <unordered_set>
#include <vector>

int longestBalanced(std::vector<int> &nums) {
  int n = nums.size();
  int result = 0;
  for (int i = 0; i < n; i++) {
    std::unordered_set<int> odd, even;
    for (int j = i; j < n; j++) {
      int num = nums[j];
      if (num % 2 == 0) {
        even.insert(num);
      } else {
        odd.insert(num);
      }
      if (even.size() == odd.size()) {
        result = std::max(result, j - i + 1);
      }
    }
  }
  return result;
}
