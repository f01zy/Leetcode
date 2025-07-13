#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

bool compare(const int &left, const int &right)
{
  return left > right;
}

std::vector<std::string> findRelativeRanks(std::vector<int> &score)
{
  std::vector<int> ranks = score;
  std::sort(ranks.begin(), ranks.end(), compare);

  std::vector<std::string> result;

  for (int i = 0; i < score.size(); i++)
  {
    int rank = std::distance(ranks.begin(), std::find(ranks.begin(), ranks.end(), score[i]));

    if (rank == 0)
    {
      result.push_back("Gold Medal");
    }

    else if (rank == 1)
    {
      result.push_back("Silver Medal");
    }

    else if (rank == 2)
    {
      result.push_back("Bronze Medal");
    }

    else
    {
      result.push_back(std::to_string(rank + 1));
    }
  }

  return result;
}

int main()
{
  std::vector<int> score = {10, 3, 8, 9, 4};
  std::vector<std::string> ranks = findRelativeRanks(score);

  for (std::string &rank : ranks)
  {
    std::cout << rank << std::endl;
  }
}