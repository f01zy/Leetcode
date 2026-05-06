#include <vector>
using namespace std;

vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid) {
  int m = boxGrid.size(), n = boxGrid[0].size();
  vector<vector<char>> ans(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans[i][j] = boxGrid[m - j - 1][i];
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      char ch = ans[i][j];
      if (ch == '#') {
        int k = i;
        while (k < n - 1) {
          char next = ans[k + 1][j];
          if (next != '.') break;
          k++;
        }
        ans[i][j] = '.';
        ans[k][j] = '#';
      }
    }
  }
  return ans;
}
