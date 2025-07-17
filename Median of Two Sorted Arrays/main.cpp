#include <vector>
#include <algorithm>
#include <cmath>

double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
{
  for (int i = 0; i < nums2.size(); i++)
  {
    nums1[nums1.size() + i] = nums2[i];
  }
  std::sort(nums1.begin(), nums1.end());
  int mid = std::floor(nums1.size() / 2);
  if (nums1.size() % 2 == 0)
  {
    return (double)(nums1[mid] + nums1[mid - 1]) / 2;
  }
  return nums1[mid];
}