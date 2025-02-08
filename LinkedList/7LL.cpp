//Array to linkedlist

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    // // Default constructor
    // Node() {
    //     data = 0;
    //     next = nullptr;
    // }

    // Parameterized Constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// class Solution {
// public:
    Node *constructLL(vector<int> &arr) {
        if (arr.empty()) return NULL;

        Node *head = new Node(arr[0]);
        Node *curr = head;

        for (int i = 1; i < arr.size(); i++) {
            curr->next = new Node(arr[i]);
            curr = curr->next;
        }
        return head;
    }

    void printLL(Node *head) {
        Node *curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
// };

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = constructLL(arr);
    printLL(head);

    return 0;
}