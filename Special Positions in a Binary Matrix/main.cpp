#include <vector>
using namespace std;

int rows[100];
int cols[100];

int numSpecial(vector<vector<int>> &mat) {
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      if (mat[i][j]) {
        rows[i]++;
        cols[j]++;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      if (mat[i][j] && rows[i] == 1 && cols[j] == 1) {
        ans++;
      }
    }
  }
  return ans;
}
