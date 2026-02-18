bool hasAlternatingBits(int n) {
  int prev = !(n & 1);
  while (n) {
    if ((n & 1) != !prev) {
      return false;
    }
    prev = !prev;
    n >>= 1;
  }
  return true;
}
