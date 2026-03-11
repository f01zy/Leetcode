#include <climits>
#include <vector>
using namespace std;

int minimumIndex(vector<int> &capacity, int itemSize) {
  int ans{-1}, size{INT_MAX};
  for (int i = 0; i < capacity.size(); i++) {
    if (capacity[i] >= itemSize && capacity[i] < size) {
      ans = i;
      size = capacity[i];
    }
  }
  return ans;
}
