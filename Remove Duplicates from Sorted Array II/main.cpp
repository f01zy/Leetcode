#include <vector>
#include <iostream>
#include <unordered_map>

int removeDuplicates(std::vector<int> &nums)
{
  std::unordered_map<int, int> numsCounter;
  int moves = 0;
  int size = nums.size();

  for (int i = 0; i < size; i++)
  {
    if (i == size - moves)
    {
      break;
    }

    int num = nums[i];

    if (numsCounter.count(num) == 0)
    {
      numsCounter[num] = 0;
    }

    numsCounter[num]++;
    int count = numsCounter[num];

    if (count > 2)
    {
      int start = i + 1;
      int end = size - moves - 1;

      for (int i = start; i <= end; i++)
      {
        nums[i - 1] = nums[i];
      }

      nums[end] = -1;
      i--;
      moves++;
    }
  }

  return nums.size() - moves;
}

int main()
{
  std::vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};

  int elements = removeDuplicates(nums);
  std::cout << elements << std::endl;

  for (int i : nums)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}