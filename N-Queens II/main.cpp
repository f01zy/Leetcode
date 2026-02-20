int result = 0;
int cache[9][9]{0};

void setQueen(int n, int i, int j, int state) {
  for (int step = 0; step < 10; step++) {
    if (i - step >= 0) {
      cache[i - step][j] += state;
    }
    if (i + step < n) {
      cache[i + step][j] += state;
    }
    if (j - step >= 0) {
      cache[i][j - step] += state;
    }
    if (j + step < n) {
      cache[i][j + step] += state;
    }
    if (i - step >= 0 && j - step >= 0) {
      cache[i - step][j - step] += state;
    }
    if (i - step >= 0 && j + step < n) {
      cache[i - step][j + step] += state;
    }
    if (i + step < n && j - step >= 0) {
      cache[i + step][j - step] += state;
    }
    if (i + step < n && j + step < n) {
      cache[i + step][j + step] += state;
    }
  }
}

void solve(const int &n, int i) {
  if (i >= n) {
    result++;
    return;
  }
  for (int j = 0; j < n; j++) {
    if (!cache[i][j]) {
      setQueen(n, i, j, 1);
      solve(n, i + 1);
      setQueen(n, i, j, -1);
    }
  }
}

int totalNQueens(int n) {
  solve(n, 0);
  return result;
}
