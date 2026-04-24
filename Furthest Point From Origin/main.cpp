#include <string>
using namespace std;

int furthestDistanceFromOrigin(string moves) {
  int l = 0, r = 0, s = 0;
  for (int i = 0; i < moves.size(); i++) {
    if (moves[i] == '_') s++;
    else if (moves[i] == 'R')
      r++;
    else if (moves[i] == 'L')
      l++;
  }
  return max(l, r) - min(l, r) + s;
}
