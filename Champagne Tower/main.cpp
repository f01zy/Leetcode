#include <vector>

double champagneTower(int poured, int query_row, int query_glass) {
  double tower[101][101]{0};
  tower[0][0] = static_cast<double>(poured);
  for (int i = 0; i <= query_row; i++) {
    for (int j = 0; j <= i; j++) {
      if (tower[i][j] > 1) {
        double excess = (tower[i][j] - 1) / 2;
        tower[i][j] = 1;
        tower[i + 1][j] += excess;
        tower[i + 1][j + 1] += excess;
      }
    }
  }
  return tower[query_row][query_glass];
}
