#include <vector>
using namespace std;

bool areSimilar(vector<vector<int>> &mat, int k) {
  int m = mat.size(), n = mat[0].size();
  k %= n;
  vector<vector<int>> temp = mat;
  while (k > 0) {
    for (int i = 0; i < m; i++) {
      if (i % 2) {
        int num = temp[i][n - 1];
        temp[i].pop_back();
        temp[i].emplace(temp[i].begin(), num);
      } else {
        int num = temp[i][0];
        temp[i].erase(temp[i].begin());
        temp[i].push_back(num);
      }
    }
    k--;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[i][j] != temp[i][j]) { return false; }
    }
  }
  return true;
}
