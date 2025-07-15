#include <string>

int lengthOfLastWord(std::string s)
{
  int result = 0;
  for (int i = s.size() - 1; i >= 0; i--)
  {
    if (s[i] != ' ')
    {
      result++;
    }
    else if (s[i] == ' ' && result == 0)
    {
      continue;
    }
    else
    {
      break;
    }
  }
  return result;
}