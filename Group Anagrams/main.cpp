#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
  unordered_map<string, int> cache;
  vector<vector<string>> ans;
  for (int i = 0; i < strs.size(); i++) {
    string &curr = strs[i];
    string temp = curr;
    sort(temp.begin(), temp.end());
    if (cache.count(temp)) {
      ans[cache[temp]].push_back(curr);
    } else {
      ans.push_back({curr});
      cache[temp] = ans.size() - 1;
    }
  }
  return ans;
}
