struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head) {
  if (!head || !head->next) {
    return head;
  }

  ListNode *node = head;
  while (node && node->next) {
    if (node->val == node->next->val) {
      if (node->next->next) {
        node->next = node->next->next;
      }

      else {
        node->next = nullptr;
        break;
      }
    }

    else {
      node = node->next;
    }
  }

  return head;
}
