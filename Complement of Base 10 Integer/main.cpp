int bitwiseComplement(int n) {
  if (n == 0) {
    return 1;
  }
  return ~n & ~(~0 << (32 - __builtin_clz(n)));
}
