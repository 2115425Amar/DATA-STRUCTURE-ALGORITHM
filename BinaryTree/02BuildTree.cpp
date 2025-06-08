#include<iostream>
#include<vector>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

// node* buildTree(node* root) {
//     cout << "Enter the data: " << endl;
//     int data;
//     cin >> data;
//     root = new node(data);    

//     if(data == -1) {
//         return NULL;
//     }
//     cout << " left ka data " << data << endl;
//     root->left = buildTree(root->left);
//     cout << "right ka data " << data << endl;
//     root->right = buildTree(root->right);
//     return root;
// }

node* buildTreeFromVector(vector<int>& data, int& index) {
    if(index >= data.size() || data[index] == -1) {
        index++;
        return NULL;
    }
    node* root = new node(data[index]);
    // index++;
    root->left = buildTreeFromVector(data, index );
    root->right = buildTreeFromVector(data, index);
    return root;
}


void inorder(node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> data = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    int index = 0;
    node* root = buildTreeFromVector(data, index);

    cout << "Inorder traversal is: ";
    inorder(root);

    return 0;
}
