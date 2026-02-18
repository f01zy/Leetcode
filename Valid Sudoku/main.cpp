#include <unordered_map>
#include <vector>

bool isValidSudoku(std::vector<std::vector<char>> &board) {
  // 1-9 rows
  // 9-18 cols
  // 18-27 blocks
  std::vector<std::unordered_map<char, int>> cache(27);
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      char ch = board[i][j];
      if (ch == '.') {
        continue;
      }
      int x = j / 3;
      int y = i / 3;
      cache[i][ch]++;
      cache[9 + j][ch]++;
      cache[18 + (x + y * 3)][ch]++;
    }
  }
  for (std::unordered_map<char, int> i : cache) {
    for (auto it = i.begin(); it != i.end(); it++) {
      if (it->second > 1) {
        return false;
      }
    }
  }
  return true;
}
