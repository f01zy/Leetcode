#include <string>
using namespace std;

string convert(string s, int rows) {
  if (rows == 1) return s;
  int cols = 1000;
  char mat[rows][cols];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      mat[i][j] = ' ';
    }
  }
  bool isZigzag = false;
  for (int i = 0, j = 0, k = 0; i < s.size(); i++) {
    mat[j][k] = s[i];
    if (j == 0) isZigzag = false;
    if (j == rows - 1) isZigzag = true;
    if (isZigzag) {
      j--;
      k++;
    } else {
      j++;
    }
  }
  string result;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (mat[i][j] != ' ') result.push_back(mat[i][j]);
    }
  }
  return result;
}
