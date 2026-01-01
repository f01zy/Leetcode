#include <vector>

void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
  for (int i = 0; i < n; i++) {
    nums1[m + i] = nums2[i];
  }

  for (int i = 0; i < m + n - 1; i++) {
    if (nums1[i + 1] < nums1[i]) {
      int temp = nums1[i];
      nums1[i] = nums1[i + 1];
      nums1[i + 1] = temp;
      i -= i == 0 ? 1 : 2;
    }
  }
}
