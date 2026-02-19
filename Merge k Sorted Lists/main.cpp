#include <queue>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
  if (lists.empty()) {
    return nullptr;
  }
  priority_queue<int, vector<int>, greater<int>> nums;
  for (int i = 0; i < lists.size(); i++) {
    ListNode *node = lists[i];
    while (node) {
      nums.push(node->val);
      node = node->next;
    }
  }
  if (nums.empty()) {
    return nullptr;
  }
  ListNode *result = new ListNode(nums.top());
  ListNode *node = result;
  nums.pop();
  while (!nums.empty()) {
    node->next = new ListNode(nums.top());
    node = node->next;
    nums.pop();
  }
  return result;
}
