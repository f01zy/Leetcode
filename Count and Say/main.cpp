#include <string>
using namespace std;

string countAndSay(int n) {
  if (n == 1) {
    return "1";
  }
  string result = "";
  string prev = countAndSay(n - 1);
  for (int i = 0; i < prev.size(); i++) {
    int count = 0;
    int j = i;
    while (prev[i] == prev[j]) {
      count++;
      j++;
    }
    result = result + to_string(count) + prev[i];
    i = j - 1;
  }
  return result;
}
