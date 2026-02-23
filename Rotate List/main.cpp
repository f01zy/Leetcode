#include <stack>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k) {
  if (!head || !head->next) {
    return head;
  }

  ListNode *node = head;
  int n = 0;
  while (node) {
    node = node->next;
    n++;
  }
  k %= n;

  stack<ListNode *> cache;
  while (k > 0) {
    ListNode *node = head;
    ListNode *tail = head;
    while (node) {
      cache.push(node);
      tail = node;
      node = node->next;
    }
    while (k > 0 && !cache.empty()) {
      ListNode *tail = cache.top();
      cache.pop();
      if (!cache.empty()) {
        cache.top()->next = nullptr;
      }
      tail->next = head;
      head = tail;
      k--;
    }
    if (k != 0) {
      tail->next = nullptr;
    }
  }
  return head;
}
