int concatenatedBinary(int n) {
  long long num = 0;
  for (int i = 1; i <= n; i++) {
    int bits = 0, j = i;
    while (j) {
      bits++;
      j >>= 1;
    }
    num = (num << bits) + i;
    num %= 1000000007;
  }
  return num;
}
