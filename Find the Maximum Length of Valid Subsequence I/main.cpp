#include <vector>

int zeroCoefficient(std::vector<int> nums)
{
  int even = 0;
  int odd = 0;
  int deletions = 0;
  for (int num : nums)
  {
    num % 2 == 0 ? even++ : odd++;
  }
  int k = even >= odd ? 0 : 1;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] % 2 != k)
    {
      deletions++;
    }
  }
  return nums.size() - deletions;
}

int unitCoefficient(std::vector<int> nums)
{
  int previousNumberParity = nums[0] % 2 == 0 ? 1 : 0;
  int deletions = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    int k = nums[i] % 2;
    if (k != previousNumberParity)
    {
      previousNumberParity = k;
    }
    else
    {
      deletions++;
    }
  }
  return nums.size() - deletions;
}

int maximumLength(std::vector<int> &nums)
{
  int a = zeroCoefficient(nums);
  int b = unitCoefficient(nums);
  return a > b ? a : b;
}