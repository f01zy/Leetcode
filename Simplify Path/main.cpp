#include <stack>
#include <string>
using namespace std;

string simplifyPath(string path) {
  int n = path.size();
  stack<string> st;
  for (int i = 1; i < n; i++) {
    string curr;
    int j = i;
    while (j < n && path[j] != '/') {
      curr.push_back(path[j++]);
    }
    if (j == i) continue;
    i = j;
    if (curr == ".") {
      continue;
    } else if (curr == "..") {
      if (!st.empty()) st.pop();
      continue;
    } else {
      st.push(curr);
    }
  }
  string ans;
  while (!st.empty()) {
    if (ans.empty()) {
      ans = st.top();
    } else {
      ans = st.top() + "/" + ans;
    }
    st.pop();
  }
  ans.insert(ans.begin(), '/');
  return ans;
}
