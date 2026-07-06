#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/** 
 * @brief Adds two numbers represented by linked lists.
 * @param l1 The first linked list.
 * @param l2 The second linked list.
 * @return The linked list representing the sum.
 */
class Solution {
  public:
    // Function to add two numbers represented by linked lists
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* dummyHead = new ListNode(0);
      ListNode* current = dummyHead;
      int carry = 0;

      // Iterate through both linked lists until all digits are processed
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

// Helper functions to create and print linked lists
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

// Test the function with example inputs
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
