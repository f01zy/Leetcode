#include <vector>

std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
  std::vector<int> result;
  int x = matrix[0].size(), y = matrix.size();
  if (x == 1 && y == 1) {
    return matrix[0];
  }
  int t = 0, b = y - 1, l = 0, r = x - 1;
  int i = 0, j = 0;
  int direction = x == 1 ? 2 : 0;
  while (1) {
    result.push_back(matrix[i][j]);
    if (direction == 0) {
      j++;
    } else if (direction == 1) {
      j--;
    } else if (direction == 2) {
      i++;
    } else if (direction == 3) {
      i--;
    }
    if (direction == 0 && j == r && i == t) {
      if (i == b) {
        break;
      }
      direction = 2;
      t++;
    } else if (direction == 2 && j == r && i == b) {
      if (j == l) {
        break;
      }
      direction = 1;
      r--;
    } else if (direction == 1 && j == l && i == b) {
      if (i == t) {
        break;
      }
      direction = 3;
      b--;
    } else if (direction == 3 && j == l && i == t) {
      if (j == r) {
        break;
      }
      direction = 0;
      l++;
    }
  }
  result.push_back(matrix[i][j]);
  return result;
}
