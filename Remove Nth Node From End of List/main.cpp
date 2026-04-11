struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
  if (!head->next && n == 1) return nullptr;
  int length = 0;
  ListNode *curr = head;
  while (curr) {
    length++;
    curr = curr->next;
  }
  if (length == n) return head->next;
  ListNode *prev = nullptr;
  ListNode *removed = head;
  for (int i = 0; i <= length - n; i++) {
    if (i == length - n) {
      prev->next = removed->next;
      break;
    }
    prev = removed;
    removed = removed->next;
  }
  return head;
}
