#include <string>

int scoreOfString(std::string s)
{
  int res = 0;
  for (int i = 0; i < s.size() - 1; i++)
  {
    res += std::abs(s[i] - s[i + 1]);
  }
  return res;
}