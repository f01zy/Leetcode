struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapPairs(ListNode *head) {
  ListNode *result = head;
  ListNode *node = head;
  ListNode *prev = nullptr;
  while (node && node->next) {
    ListNode *next = node->next;
    ListNode *temp = next->next;
    next->next = node;
    node->next = temp;
    if (prev) {
      prev->next = next;
    }
    if (node == head) {
      result = next;
    }
    prev = node;
    node = node->next;
  }
  return result;
}
