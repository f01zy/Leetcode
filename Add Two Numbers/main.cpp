struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *result = new ListNode();
  ListNode *node = result;
  int remainder = 0;
  while (l1 || l2 || remainder) {
    int sum = remainder;
    if (l1) {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      sum += l2->val;
      l2 = l2->next;
    }
    if (sum >= 10) {
      node->val = sum % 10;
      remainder = 1;
    } else {
      node->val = sum;
      remainder = 0;
    }
    if (l1 || l2 || remainder) {
      node->next = new ListNode();
      node = node->next;
    }
  }
  return result;
}
