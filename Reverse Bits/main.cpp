int reverseBits(int n) {
  int r{};
  for (int i = 0; i < 16; i++) {
    if ((n >> i) & 1) {
      r |= 1 << (31 - i);
    }
    if ((n >> (31 - i)) & 1) {
      r |= 1 << i;
    }
  }
  return r;
}
