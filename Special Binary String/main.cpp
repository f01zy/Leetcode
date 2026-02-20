#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string process(string &s) {
  if (s.size() <= 2) {
    return s;
  }
  vector<string> parts;
  string part;
  int state = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      state++;
    } else {
      state--;
    }
    part.push_back(s[i]);
    if (state == 0) {
      parts.push_back(part);
      part.clear();
    }
  }
  for (string &part : parts) {
    string sliced = part;
    sliced.erase(sliced.size() - 1, 1);
    sliced.erase(0, 1);
    part = "1" + process(sliced) + "0";
  }
  sort(parts.begin(), parts.end(), greater<string>());
  string result;
  for (string &part : parts) {
    result = result + part;
  }
  return result;
}

string makeLargestSpecial(string s) {
  return process(s);
}
