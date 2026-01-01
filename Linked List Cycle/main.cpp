struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *node) {
  while (node) {
    if (node->next && node->next <= node) {
      return true;
    }
    node = node->next;
  }

  return false;
}
