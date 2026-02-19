struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getSize(ListNode *head) {
  if (!head) {
    return 0;
  }
  int size = 0;
  while (head) {
    size++;
    head = head->next;
  }
  return size;
}

ListNode *reverseKGroup(ListNode *head, int k) {
  ListNode *currentHead = head;
  ListNode *currentTail = head;
  ListNode *prev = nullptr;
  ListNode *result = head;
  int steps = k / 2;
  int n = getSize(head);
  int pairs = n / k;
  for (int i = 0; i < pairs; i++) {
    ListNode *nextGroupHead = nullptr;
    ListNode *nextGroupPrev = nullptr;
    for (int step = 0; step < steps; step++) {
      ListNode *prevOfTail = nullptr;
      for (int j = 0; j < k - step * 2 - 1; j++) {
        prevOfTail = currentTail;
        currentTail = currentTail->next;
        if (!currentTail) {
          return result;
        }
      }
      if (step == 0) {
        nextGroupHead = currentTail->next;
        nextGroupPrev = currentHead;
        if (i == 0) {
          result = currentTail;
        }
      }
      ListNode *temp = currentHead->next;
      currentHead->next = currentTail->next;
      if (temp == currentTail) {
        currentTail->next = currentHead;
      } else {
        currentTail->next = temp;
        prevOfTail->next = currentHead;
      }
      if (prev) {
        prev->next = currentTail;
      }
      prev = currentTail;
      currentHead = currentTail->next;
      currentTail = currentHead;
    }
    currentHead = nextGroupHead;
    currentTail = nextGroupHead;
    prev = nextGroupPrev;
  }
  return result;
}
