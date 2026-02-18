#include <vector>

int charToNumber(char ch) { return ch - '0'; }

bool isValidSudoku(std::vector<std::vector<char>> &board) {
  int rows[9][10]{0};
  int cols[9][10]{0};
  int boxes[9][10]{0};
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      char ch = board[i][j];
      if (ch == '.') {
        continue;
      }
      int num = charToNumber(ch);
      int x = j / 3;
      int y = i / 3;
      if (rows[i][num]++ == 1 || cols[j][num]++ == 1 || boxes[x + y * 3][num]++ == 1) {
        return false;
      }
    }
  }
  return true;
}
