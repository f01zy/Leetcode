#include <vector>
#include <iostream>
#include <algorithm>

int missingNumber(std::vector<int> &nums)
{
  int a = 0;
  int b = 0;

  for (int i = 0; i < nums.size() + 1; i++)
  {
    a += i;
  }

  for (int num : nums)
  {
    b += num;
  }

  return a - b;
}

int main()
{
  std::vector<int> nums{0, 1};
  int num = missingNumber(nums);

  std::cout << num << std::endl;
}