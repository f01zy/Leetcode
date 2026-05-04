#include <vector>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
  vector<vector<int>> ans;
  int i = 0, n = intervals.size();
  if (n == 0 || newInterval[0] > intervals[n - 1][1]) {
    intervals.push_back(newInterval);
    return intervals;
  } else if (newInterval[1] < intervals[0][0]) {
    intervals.emplace(intervals.begin(), newInterval);
    return intervals;
  }
  for (; i < n; i++) {
    vector<int> &curr = intervals[i];
    if (curr[1] < newInterval[0]) {
      ans.push_back(curr);
    } else {
      break;
    }
  }
  for (; i < n; i++) {
    vector<int> &curr = intervals[i];
    if (curr[0] > newInterval[1] || curr[1] < newInterval[0]) {
      break;
    } else {
      newInterval[0] = min(newInterval[0], curr[0]);
      newInterval[1] = max(newInterval[1], curr[1]);
    }
  }
  ans.push_back(newInterval);
  for (; i < n; i++) {
    ans.push_back(intervals[i]);
  }
  return ans;
}
