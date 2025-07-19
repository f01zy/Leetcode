struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *oddEvenList(ListNode *head)
{
  if (!head || !head->next)
  {
    return head;
  }
  ListNode *oddTail = head;
  ListNode *node = head->next;
  while (node && node->next)
  {
    ListNode *a = node->next;
    ListNode *b = a->next;
    a->next = oddTail->next;
    oddTail->next = a;
    node->next = b;
    oddTail = a;
    node = node->next;
  }
  return head;
}