#include <stack>
#include <string>
using namespace std;

int calculate(string s) {
  stack<int> signs;
  long long num = 0, result = 0;
  int sign = 1, externalSign = 1;
  for (int i = 0; i < s.size(); i++) {
    char ch = s[i];
    if (isdigit(ch)) {
      num = num * 10 + ch - '0';
    } else {
      result += num * externalSign * sign;
      num = 0;
    }
    if (ch == '+') {
      sign = 1;
    } else if (ch == '-') {
      sign = -1;
    } else if (ch == '(') {
      signs.push(externalSign);
      externalSign *= sign;
      sign = 1;
    } else if (ch == ')') {
      externalSign = signs.top();
      signs.pop();
      sign = 1;
    }
  }
  if (num) {
    result += num * sign;
  }
  return result;
}
