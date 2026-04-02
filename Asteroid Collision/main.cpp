// TODO

#include <algorithm>
#include <cstdlib>
#include <stack>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids) {
  stack<int> stack;
  for (int i = 0; i < asteroids.size(); i++) {
    int curr = asteroids[i];
    if (curr < 0) {
      int asteroid = curr;
      while (!stack.empty() && stack.top() > 0) {
        if (stack.top() < abs(curr)) stack.pop();
        else if (stack.top() > abs(curr)) {
          asteroid = 0;
          break;
        } else if (stack.top() == abs(curr)) {
          stack.pop();
          asteroid = 0;
          break;
        }
      }
      if (asteroid) stack.push(asteroid);
    } else {
      stack.push(curr);
    }
  }
  vector<int> result;
  while (!stack.empty()) {
    int top = stack.top();
    stack.pop();
    result.push_back(top);
  }
  reverse(result.begin(), result.end());
  return result;
}
