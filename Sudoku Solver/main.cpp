#include <vector>
using namespace std;

int rows[9][10]{0};
int cols[9][10]{0};
int boxes[9][10]{0};

int charToNum(char ch) { return ch - '0'; }
char numToChar(int num) { return num + '0'; }

bool isCanChangeMatrix(int i, int j, int num) {
  int x = j / 3;
  int y = i / 3;
  if (rows[i][num] >= 1 || cols[j][num] >= 1 || boxes[x + y * 3][num] >= 1) {
    return false;
  }
  return true;
}

void changeMatrix(int i, int j, int num) {
  rows[i][num]++;
  cols[j][num]++;
  int x = j / 3;
  int y = i / 3;
  boxes[x + y * 3][num]++;
}

void returnMatrix(int i, int j, int num) {
  rows[i][num]--;
  cols[j][num]--;
  int x = j / 3;
  int y = i / 3;
  boxes[x + y * 3][num]--;
}

bool solve(vector<vector<char>> &board, int i, int j) {
  if (i >= 9) {
    return true;
  }
  char ch = board[i][j];
  int ni = j == 8 ? i + 1 : i;
  int nj = j == 8 ? 0 : j + 1;
  if (ch != '.') {
    return solve(board, ni, nj);
  }
  for (int num = 1; num <= 9; num++) {
    if (!isCanChangeMatrix(i, j, num)) {
      continue;
    }
    board[i][j] = numToChar(num);
    changeMatrix(i, j, num);
    if (solve(board, ni, nj)) {
      return true;
    }
    board[i][j] = '.';
    returnMatrix(i, j, num);
  }
  return false;
}

void solveSudoku(vector<vector<char>> &board) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      char ch = board[i][j];
      if (ch == '.') {
        continue;
      }
      int num = charToNum(ch);
      changeMatrix(i, j, num);
    }
  }
  solve(board, 0, 0);
}
