#include <string>
#include <vector>
using namespace std;

vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary) {
  vector<string> ans;
  for (const string &a : queries) {
    for (const string &b : dictionary) {
      int diffs = 0;
      for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) diffs++;
      }
      if (diffs <= 2) {
        ans.push_back(a);
        break;
      }
    }
  }
  return ans;
}
