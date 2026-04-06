#include <unordered_set>
#include <vector>
using namespace std;

long long pairToNum(int x, int y) { return (long long)(x + 30000) << 32 | (y + 30000); }

int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
  unordered_set<long long> cache;
  for (const vector<int> &obstacle : obstacles) {
    cache.insert(pairToNum(obstacle[0], obstacle[1]));
  }
  int dirX = 0, dirY = 1;
  int x = 0, y = 0;
  int result = 0;
  for (int i = 0; i < commands.size(); i++) {
    if (commands[i] == -1) {
      int temp = dirX;
      dirX = dirY;
      dirY = -temp;
    } else if (commands[i] == -2) {
      int temp = dirX;
      dirX = -dirY;
      dirY = temp;
    } else {
      for (int j = 0; j < commands[i]; j++) {
        x += dirX;
        y += dirY;
        if (cache.find(pairToNum(x, y)) != cache.end()) {
          x -= dirX;
          y -= dirY;
          break;
        }
      }
      result = max(result, x * x + y * y);
    }
  }
  return result;
}
