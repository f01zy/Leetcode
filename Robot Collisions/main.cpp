#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions) {
  int n = positions.size();
  stack<pair<int, int>> robots;
  vector<pair<int, int>> p;
  for (int i = 0; i < n; i++) {
    p.push_back({positions[i], i});
  }
  sort(p.begin(), p.end(), [&](auto a, auto b) { return a.first < b.first; });

  for (int i = 0; i < n; i++) {
    int curr_index = p[i].second;
    int curr = healths[curr_index] * (directions[curr_index] == 'L' ? -1 : 1);
    if (robots.empty()) {
      robots.push({curr, curr_index});
      continue;
    }
    int index = curr_index;
    int health = curr;
    if (health < 0) {
      while (!robots.empty() && robots.top().first > 0) {
        if (robots.top().first > abs(health)) {
          robots.top().first--;
          health = 0;
          break;
        } else if (robots.top().first < abs(health)) {
          robots.pop();
          health++;
        } else {
          robots.pop();
          health = 0;
          break;
        }
      }
      if (health != 0) robots.push({health, index});
    } else {
      robots.push({health, index});
    }
  }

  vector<pair<int, int>> temp;
  while (!robots.empty()) {
    auto curr = robots.top();
    robots.pop();
    temp.push_back(curr);
  }
  sort(temp.begin(), temp.end(), [&](auto a, auto b) { return a.second < b.second; });
  vector<int> result;
  for (int i = 0; i < temp.size(); i++) {
    result.push_back(abs(temp[i].first));
  }
  return result;
}
