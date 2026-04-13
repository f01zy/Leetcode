#include <vector>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target) {
  if (!nums.size()) return {-1, -1};
  int start = 0, end = nums.size() - 1, mid = 0;
  while (start < end) {
    mid = (start + end) / 2;
    if (nums[mid] < target) start = mid + 1;
    else if (nums[mid] >= target)
      end = mid;
  }
  if (nums[start] != target) return {-1, -1};
  int left = start, right = start;
  while (1) {
    bool isChanged = false;
    if (left >= 1 && nums[left - 1] == target) {
      left--;
      isChanged = true;
    }
    if (right < nums.size() - 1 && nums[right + 1] == target) {
      right++;
      isChanged = true;
    }
    if (!isChanged) break;
  }
  return {left, right};
}
