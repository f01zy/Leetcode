#include <vector>

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