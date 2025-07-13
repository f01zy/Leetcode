#include <vector>
#include <iostream>
#include <string>
#include <format>

void writeRange(int start, int end, std::vector<int> &nums, std::vector<std::string> &ranges)
{
  std::string range;

  if (start == end)
  {
    range = std::to_string(start);
  }

  else
  {
    range = std::to_string(start) + "->" + std::to_string(end);
  }

  ranges.push_back(range);
}

std::vector<std::string> summaryRanges(std::vector<int> &nums)
{
  std::vector<std::string> ranges;

  if (nums.size() == 0)
  {
    return ranges;
  }

  int start = nums[0];
  int end = nums[0];

  if (nums.size() == 1)
  {
    writeRange(start, end, nums, ranges);
    return ranges;
  }

  for (int i = 1; i < nums.size(); i++)
  {
    bool isRange = nums[i - 1] + 1 == nums[i];

    if (isRange)
    {
      end = nums[i];
    }

    if (!isRange)
    {
      writeRange(start, end, nums, ranges);
      start = nums[i];
      end = nums[i];
    }

    if (i == nums.size() - 1)
    {
      writeRange(start, end, nums, ranges);
    }
  }

  return ranges;
}

int main()
{
  std::vector<int> nums = {};
  std::vector<std::string> ranges = summaryRanges(nums);

  for (std::string range : ranges)
  {
    std::cout << range << std::endl;
  }
}