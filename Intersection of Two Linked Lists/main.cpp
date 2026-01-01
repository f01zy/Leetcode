struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  ListNode *tailA = headA;
  while (tailA->next) {
    tailA = tailA->next;
  }
  ListNode *node = headB;
  while (node) {
    if (node >= headA && node <= tailA) {
      return node;
    }
    node = node->next;
  }
  return nullptr;
}
