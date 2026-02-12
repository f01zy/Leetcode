#include <string>
#include <unordered_map>

int longestBalanced(std::string s) {
  int r = 0, n = s.size();
  for (int i = 0; i < n; i++) {
    std::unordered_map<char, int> cache;
    for (int j = i; j < n; j++) {
      char ch = s[j];
      int c = ++cache[ch];
      bool isBalanced = true;
      for (auto it = cache.begin(); it != cache.end(); it++) {
        if (it->second != c) {
          isBalanced = false;
          break;
        }
      }
      if (isBalanced) {
        r = std::max(r, j - i + 1);
      }
    }
  }
  return r;
}
