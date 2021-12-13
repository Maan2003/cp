#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_list(ListNode *head) {
  while (head) {
    printf("%d ", head->val);
    head = head->next;
  }
  printf("\n");
}

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr)
      return nullptr;

    ListNode *last = head;
    int len = 0;
    while (last->next != nullptr) {
      len++;
      last = last->next;
    }
    len++;
    // make it a circular a linked list
    last->next = head;
    if (k > len) {
      k %= len;
    }
    k = len - k;

    ListNode *kth = last;
    // go to index k, i.e node before k
    for (int i = 0; i < k; i++) {
      kth = kth->next;
    }
    ListNode *newHead = kth->next;
    // break this link
    kth->next = nullptr;
    return newHead;
  }
};

int main() {
  ListNode x(5);
  ListNode y(4, &x);
  ListNode z(3, &y);
  ListNode a(2, &z);
  ListNode h(1, &a);
  Solution sol;
  sol.rotateRight(&h, 2);
}
