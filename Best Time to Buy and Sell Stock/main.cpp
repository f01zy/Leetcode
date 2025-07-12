#include <vector>
#include <iostream>

int getLarger(std::vector<int> &prices, int start, int end)
{
  int larger = prices[start];

  for (int i = start; i <= end; i++)
  {
    if (prices[i] > larger)
    {
      larger = prices[i];
    }
  }

  return larger;
}

int maxProfit(std::vector<int> &prices)
{
  int size = prices.size();
  int res = 0;

  for (int i = 0; i < size - 1; i++)
  {
    int buy = prices[i];
    int sell = getLarger(prices, i + 1, prices.size() - 1);
    int profit = sell - buy;

    if (profit > res)
    {
      res = profit;
    }
  }

  return res;
}

int main()
{
  std::vector<int> prices = {7, 1, 5, 3, 6, 4};

  maxProfit(prices);
}