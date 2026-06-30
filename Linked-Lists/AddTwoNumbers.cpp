#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* dummyHead = new ListNode(0);
      ListNode* current = dummyHead;
      int carry = 0;

      while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int currentSum = carry;

        if (l1 != nullptr) {
          currentSum += l1->val;
          l1 = l1->next;
        }

        if (l2 != nullptr) {
          currentSum += l2->val;
          l2 = l2->next;
        }

        carry = currentSum / 10;

        current->next = new ListNode(currentSum % 10);
        current = current->next;
      }

      ListNode* result = dummyHead->next;
      delete dummyHead;

      return result;
    }
};

ListNode* createList(const std::vector<int>& nums) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* current = dummyHead;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    ListNode* head = dummyHead->next;
    delete dummyHead;
    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

void freeList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

int main() {
    Solution solver;

    std::vector<int> nums1 = {2, 4, 3};
    std::vector<int> nums2 = {5, 6, 4};

    ListNode* l1 = createList(nums1);
    ListNode* l2 = createList(nums2);

    std::cout << std::endl;
    std::cout << "--- Initial Data ---" << std::endl;
    std::cout << "List 1: ";
    printList(l1);
    std::cout << "List 2: ";
    printList(l2);

    ListNode* result = solver.addTwoNumbers(l1, l2);

    std::cout << "--- Result ---" << std::endl;
    std::cout << "Sum:    ";
    printList(result);

    freeList(l1);
    freeList(l2);
    freeList(result);

    return 0;
}
