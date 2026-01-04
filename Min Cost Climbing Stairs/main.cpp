#include <vector>

int getMinCostClimbingStairs(std::vector<int> &cost, std::vector<int> &dp, int i) {
  if (i == cost.size() - 1 || i == cost.size() - 2) {
    return cost[i];
  }
  if (i == cost.size() - 3) {
    return cost[i] + std::min(cost[i + 1], cost[i + 2]);
  }
  if (dp[i] != -1) {
    return dp[i];
  }
  int a = getMinCostClimbingStairs(cost, dp, i + 1);
  int b = getMinCostClimbingStairs(cost, dp, i + 2);
  int m = std::min(a, b);
  int c = cost[i] + m;
  dp[i] = c;
  return c;
}

int minCostClimbingStairs(std::vector<int> &cost) {
  std::vector<int> dp(cost.size(), -1);
  int a = getMinCostClimbingStairs(cost, dp, 0);
  int b = getMinCostClimbingStairs(cost, dp, 1);
  return std::min(a, b);
}
