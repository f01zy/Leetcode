#include <vector>
#include <iostream>
#include <unordered_map>

int singleNumber(std::vector<int> &nums)
{
  std::unordered_map<int, int> numsCounter;

  for (int num : nums)
  {
    if (numsCounter.count(num) == 0)
    {
      numsCounter[num] = 0;
    }

    numsCounter[num]++;
  }

  for (const auto &num : numsCounter)
  {
    if (num.second == 1)
    {
      return num.first;
    }
  }

  return -1;
}

int main()
{
  std::vector<int> nums = {4, 1, 2, 1, 2};
  int num = singleNumber(nums);

  std::cout << num << std::endl;
}