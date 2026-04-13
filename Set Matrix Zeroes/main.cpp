#include <vector>
using namespace std;

void setZeroes(vector<vector<int>> &matrix) {
  int m = matrix.size(), n = matrix[0].size();
  vector<bool> rows(m), cols(n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!matrix[i][j]) rows[i] = cols[j] = true;
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] && (rows[i] || cols[j])) matrix[i][j] = 0;
    }
  }
}
