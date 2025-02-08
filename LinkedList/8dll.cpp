#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node(){
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value){
        prev = NULL;
        data = value;
        next = NULL;
    }
};

    
    Node* constructDLL(vector<int>& arr) {
        int n = arr.size();
        Node* head = new Node(arr[0]);
        Node* temp = head;
        
        for(int i=1; i<n; i++){
            temp->next=new Node(arr[i]);
            temp->next->prev = temp;
            temp=temp->next;
        }
        return head;
    }

void printDLL(Node* head) {
    Node* temp = head;
    cout << temp->data << " ";
    while (temp != NULL) {
        cout << temp->data << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = constructDLL(arr);
    printDLL(head);
    return 0;
}