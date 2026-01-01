#include <string>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string> &strs) {
  std::string result = "";

  for (int i = 0; i < strs[0].size(); i++) {
    char ch = strs[0][i];
    for (int j = 1; j < strs.size(); j++) {
      if (strs[j][i] != ch) {
        return result;
      }
    }
    result.push_back(ch);
  }

  return result;
}
