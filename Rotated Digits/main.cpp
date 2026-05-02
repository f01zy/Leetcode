int rotatedDigits(int n) {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    bool isValid = true;
    int num = i, rotated = 0, factor = 1;
    while (num) {
      int digit = num % 10;
      if (digit == 3 || digit == 4 || digit == 7) {
        isValid = false;
        break;
      }
      rotated += factor * (digit == 2 ? 5 : digit == 5 ? 2 : digit == 6 ? 9 : digit == 9 ? 6 : digit);
      num /= 10;
      factor *= 10;
    }
    if (isValid && rotated != i) ans++;
  }
  return ans;
}
