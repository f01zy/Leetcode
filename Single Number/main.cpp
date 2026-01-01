#include <unordered_map>
#include <vector>

int singleNumber(std::vector<int> &nums) {
  std::unordered_map<int, int> numsCounter;

  for (int num : nums) {
    if (numsCounter.count(num) == 0) {
      numsCounter[num] = 0;
    }

    numsCounter[num]++;
  }

  for (const auto &num : numsCounter) {
    if (num.second == 1) {
      return num.first;
    }
  }

  return -1;
}
