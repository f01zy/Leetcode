#include <string>
using namespace std;

string result = "0";

void invert(string &str) {
  for (int i = 0; i < str.size(); i++) {
    str[i] = str[i] == '0' ? '1' : '0';
  }
}

void reverse(string &str) {
  int n = str.size();
  for (int i = 0; i != n - i - 1; i++) {
    char temp = str[i];
    str[i] = str[n - i - 1];
    str[n - i - 1] = temp;
  }
}

void process(int curr, int n) {
  string temp = result;
  invert(temp);
  reverse(temp);
  result = result + "1" + temp;
  if (curr < n) {
    process(curr + 1, n);
  }
}

char findKthBit(int n, int k) {
  if (n == 1) {
    return '0';
  }
  process(2, n);
  return result[k - 1];
}
