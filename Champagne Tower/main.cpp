#include <vector>

double champagneTower(int poured, int query_row, int query_glass) {
  std::vector<std::vector<double>> glasses(100, std::vector<double>(100, 0));
  glasses[0][0] = static_cast<double>(poured);
  for (int i = 0; i < query_row + 1; i++) {
    for (int j = 0; j < i + 1; j++) {
      double currentPoured = glasses[i][j];
      if (currentPoured > 1) {
        double remainder = currentPoured - 1;
        glasses[i][j] = 1;
        if (i < 99) {
          glasses[i + 1][j] += remainder / 2;
          glasses[i + 1][j + 1] += remainder / 2;
        }
      }
    }
  }
  return glasses[query_row][query_glass];
}
