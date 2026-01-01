#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode *head) {
  std::vector<int> nums;
  while (head) {
    nums.push_back(head->val);
    head = head->next;
  }
  for (int i = 0; i < nums.size() / 2; i++) {
    if (nums[i] != nums[nums.size() - 1 - i]) {
      return false;
    }
  }

  return true;
}
