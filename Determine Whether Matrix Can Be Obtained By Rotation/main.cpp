#include <vector>
using namespace std;

void transpose(vector<vector<int>> &mat) {
  int n = mat.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int temp = mat[i][j];
      mat[i][j] = mat[j][i];
      mat[j][i] = temp;
    }
  }
}

void reverse(vector<vector<int>> &mat) {
  int n = mat.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n / 2; j++) {
      int temp = mat[i][j];
      mat[i][j] = mat[i][n - j - 1];
      mat[i][n - j - 1] = temp;
    }
  }
}

bool compare(vector<vector<int>> &mat, vector<vector<int>> &target) {
  int n = mat.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[i][j] != target[i][j]) { return false; }
    }
  }
  return true;
}

bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target) {
  for (int i = 0; i < 4; i++) {
    transpose(mat);
    reverse(mat);
    if (compare(mat, target)) { return true; }
  }
  return false;
}
