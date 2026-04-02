#include <climits>
#include <vector>
using namespace std;

int dp[500][500][3]{0};
bool used[500][500][3]{false};

int process(vector<vector<int>> &coins, int k, int i, int j) {
  int cost = coins[i][j];
  int m = coins.size(), n = coins[0].size();
  if (i == m - 1 && j == n - 1) {
    if (cost < 0 && k > 0) return 0;
    return cost;
  };
  if (used[i][j][k]) return dp[i][j][k];
  int amount = INT_MIN;

  if (i < m - 1) amount = max(amount, cost + process(coins, k, i + 1, j));
  if (i < m - 1 && cost < 0 && k > 0) amount = max(amount, process(coins, k - 1, i + 1, j));
  if (j < n - 1) amount = max(amount, cost + process(coins, k, i, j + 1));
  if (j < n - 1 && cost < 0 && k > 0) amount = max(amount, process(coins, k - 1, i, j + 1));

  dp[i][j][k] = amount;
  used[i][j][k] = true;
  return amount;
}

int maximumAmount(vector<vector<int>> &coins) { return process(coins, 2, 0, 0); }
