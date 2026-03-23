int integerBreak(int num) {
  int result = 1;
  if (num == 2) { return 1; }
  if (num == 3) { return 2; }
  while (num > 4) {
    result *= 3;
    num -= 3;
  }
  return result * num;
}
