#include <iostream>

class ListNode {
public:
    int val;                  // Value of the node
    ListNode *next;           // Pointer to the next node

    // Default constructor
    ListNode() : val(0), next(nullptr) {}

    // Constructor with value initialization
    ListNode(int x) : val(x), next(nullptr) {}

    // Constructor with value and next node pointer initialization
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    // Method to find the middle node of a singly linked list
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head; // Fast pointer
        ListNode* slow = head; // Slow pointer

        // Traverse the list
        while (fast && fast->next) {
            slow = slow->next; // Move slow pointer one step
            fast = fast->next->next; // Move fast pointer two steps
        }

        // Return the slow pointer, which points to the middle node
        return slow;
    }
};

void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create a Solution object
    Solution solution;

    // Find the middle node
    ListNode* middle = solution.middleNode(head);

    // Print the value of the middle node
    std::cout << "Middle node value: " << middle->val << std::endl;

    // Print the entire list starting from the middle node
    std::cout << "List from middle node: ";
    printList(middle);

    return 0;
}