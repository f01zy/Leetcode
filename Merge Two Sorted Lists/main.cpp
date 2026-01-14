struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  if (!list1 && list2) {
    return list2;
  } else if ((list1 && !list2) || (!list1 && !list2)) {
    return list1;
  }
  bool isFirstListSelected = list1->val >= list2->val ? true : false;
  ListNode *p1 = isFirstListSelected ? list1 : list2;
  ListNode *p2 = isFirstListSelected ? list2 : list1;
  while (1) {
    if (!p2) {
      break;
    }
    if (!p1->next) {
      p1->next = p2;
      break;
    }
    if (p2->val >= p1->val) {
      ListNode *temp = p2->next;
      p2->next = p1->next;
      p1->next = p2;
      p1 = p1->next->next;
      p2 = temp;
    }
  }
  return isFirstListSelected ? list1 : list2;
}
