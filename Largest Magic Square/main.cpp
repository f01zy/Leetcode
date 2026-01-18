#include <vector>

// Fuck this problem

int largestMagicSquare(std::vector<std::vector<int>> &grid) {
  int m = grid.size();
  int n = grid[0].size();
  std::vector<std::vector<int>> rows(m, std::vector<int>(n, 0));
  std::vector<std::vector<int>> cols(m, std::vector<int>(n, 0));
  std::vector<std::vector<int>> firstDiagonals(m, std::vector<int>(n, 0));
  std::vector<std::vector<int>> seconsDiagonals(m, std::vector<int>(n, 0));
  int result = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int num = grid[i][j];
      rows[i][j] = j == 0 ? num : rows[i][j - 1] + num;
      cols[i][j] = i == 0 ? num : cols[i - 1][j] + num;
      firstDiagonals[i][j] = (i == 0 || j == 0) ? num : firstDiagonals[i - 1][j - 1] + num;
      seconsDiagonals[i][j] = (i == 0 || j == n - 1) ? num : seconsDiagonals[i - 1][j + 1] + num;
      for (int side = 2; (i - side + 1 >= 0) && (j - side + 1 >= 0); side++) {
        int firstDiagonal = firstDiagonals[i][j];
        int secondDiagonal = seconsDiagonals[i][j - side + 1];
        int row = rows[i][j];
        int col = cols[i][j];
        if (i + 1 > side && j + 1 > side) {
          firstDiagonal -= firstDiagonals[i - side][j - side];
        }
        if (i + 1 > side && j + 1 < n) {
          secondDiagonal -= seconsDiagonals[i - side][j + 1];
        }
        if (j - side >= 0) {
          row -= rows[i][j - side];
        }
        if (i - side >= 0) {
          col -= cols[i - side][j];
        }
        if (firstDiagonal != secondDiagonal || row != col || row != firstDiagonal) {
          continue;
        }
        int shift = 1;
        bool isMagicSquare = true;
        while (shift < side) {
          int tempRow = rows[i - shift][j];
          int tempCol = cols[i][j - shift];
          if (j - side >= 0) {
            tempRow -= rows[i - shift][j - side];
          }
          if (i - side >= 0) {
            tempCol -= cols[i - side][j - shift];
          }
          if (tempRow != row || tempCol != col) {
            isMagicSquare = false;
            break;
          }
          shift++;
        }
        if (isMagicSquare) {
          result = std::max(result, side);
        }
      }
    }
  }
  return result;
}
