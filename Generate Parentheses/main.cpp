#include <string>
#include <vector>

std::vector<std::string> generateParenthesis(int n) {
  std::vector<std::vector<std::string>> cache(n + 1);
  cache[0] = {""};
  for (int currentLevel = 1; currentLevel <= n; currentLevel++) {
    std::vector<std::string> levelResult{};
    for (int k = 0; k < currentLevel; k++) {
      std::vector<std::string> &a = cache[k];
      std::vector<std::string> &b = cache[currentLevel - k - 1];
      for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
          levelResult.push_back("(" + a[i] + ")" + b[j]);
        }
      }
    }
    cache[currentLevel] = levelResult;
  }
  return cache[n];
}
