#include <vector>
#include <cmath>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getDecimalValue(ListNode *head)
{
  std::vector<int> nums;
  int result = 0;

  ListNode *node = head;
  while (node)
  {
    nums.push_back(node->val);
    node = node->next;
  }

  for (int i = 0; i < nums.size(); i++)
  {
    result += nums[i] * static_cast<int>(std::pow(2, nums.size() - i - 1));
  }

  return result;
}