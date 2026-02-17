#include <string>
#include <vector>

// 1 - top
// 2 - bottom
// 3 - left
// 4 - right

bool dp[6][6];

bool traversal(std::vector<std::vector<char>> &board, std::string &word, int i, int j, int k, int f) {
  if (k >= word.size()) {
    return true;
  }
  int m = board.size(), n = board[0].size();
  bool r = false;
  dp[i][j] = true;
  if (!r && i != 0 && f != 1 && board[i - 1][j] == word[k] && !dp[i - 1][j]) {
    r += traversal(board, word, i - 1, j, k + 1, 2);
  }
  if (!r && i != m - 1 && f != 2 && board[i + 1][j] == word[k] && !dp[i + 1][j]) {
    r += traversal(board, word, i + 1, j, k + 1, 1);
  }
  if (!r && j != 0 && f != 3 && board[i][j - 1] == word[k] && !dp[i][j - 1]) {
    r += traversal(board, word, i, j - 1, k + 1, 4);
  }
  if (!r && j != n - 1 && f != 4 && board[i][j + 1] == word[k] && !dp[i][j + 1]) {
    r += traversal(board, word, i, j + 1, k + 1, 3);
  }
  dp[i][j] = false;
  return r;
}

bool exist(std::vector<std::vector<char>> &board, std::string word) {
  int m = board.size(), n = board[0].size(), w = word.size();
  if (w > m * n) {
    return false;
  }
  bool r = false;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == word[0]) {
        if (w == 1) {
          return true;
        }
        r += traversal(board, word, i, j, 1, 0);
      }
    }
  }
  return r;
}
