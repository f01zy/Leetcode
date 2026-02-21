// Решение - говно

#include <string>
using namespace std;

long long stringToNumber(string &s) {
  long long result = 0;
  for (char c : s) {
    result = result * 10 + (c - '0');
  }
  return result;
}

long long getFullNumber(string &s, int &last, int i) {
  string num;
  for (int j = i; j < s.size(); j++) {
    if (s[j] == '+' || s[j] == '-' || s[j] == ' ') {
      break;
    }
    last = j;
    num.push_back(s[j]);
  }
  return stringToNumber(num);
}

int calculate(string s) {
  int j = 0;
  while (1) {
    bool isFinished = true;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ')') {
        isFinished = false;
        s.replace(j, i - j + 1,
                  to_string(calculate(s.substr(j + 1, i - j - 1))));
        break;
      } else if (s[i] == '(') {
        j = i;
      }
    }
    if (isFinished) {
      break;
    }
  }
  long long result = 0;
  int sign = 1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') {
      continue;
    } else if (s[i] == '+') {
      sign = 1;
    } else if (s[i] == '-') {
      if (sign == -1) {
        sign = 1;
      } else {
        sign = -1;
      }
    } else {
      int last = i;
      result += getFullNumber(s, last, i) * sign;
      i = last;
      sign = 1;
    }
  }
  return result;
}
