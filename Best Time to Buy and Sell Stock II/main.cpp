#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {
  bool isPurchased = false;
  int profit = 0, n = prices.size();
  for (int i = 0; i < n; i++) {
    if (i != n - 1 && prices[i + 1] > prices[i] && !isPurchased) {
      profit -= prices[i];
      isPurchased = true;
    } else if ((i == n - 1 || prices[i + 1] < prices[i]) && isPurchased) {
      profit += prices[i];
      isPurchased = false;
    }
  }
  return profit;
}
