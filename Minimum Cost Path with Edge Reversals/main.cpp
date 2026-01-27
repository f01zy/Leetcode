#include <set>
#include <vector>

const int inf = 1e9;

int minCost(int n, std::vector<std::vector<int>> &edges) {
  std::vector<std::vector<std::pair<int, int>>> g(n, std::vector<std::pair<int, int>>{});
  std::vector<int> d(n, inf);
  std::set<std::pair<int, int>> q;
  for (const std::vector<int> &edge : edges) {
    g[edge[0]].push_back({edge[1], edge[2]});
    g[edge[1]].push_back({edge[0], edge[2] * 2});
  }
  d[0] = 0;
  q.insert({0, 0});
  while (!q.empty()) {
    int v = q.begin()->second;
    q.erase(q.begin());
    for (const auto &[u, w] : g[v]) {
      if (d[u] > d[v] + w) {
        q.erase({d[u], u});
        d[u] = d[v] + w;
        q.insert({d[u], u});
      }
    }
  }
  return d[n - 1] == inf ? -1 : d[n - 1];
}
