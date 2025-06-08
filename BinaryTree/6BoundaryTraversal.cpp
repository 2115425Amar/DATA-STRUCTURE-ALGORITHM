#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};


void traverseLeft(node* root, vector<int>& ans) {
    if ((root == NULL) || (root->left == NULL && root->right == NULL)) {  // leaf node excluded
        return;
    }
    ans.push_back(root->data);
    if (root->left) {
        traverseLeft(root->left, ans);
    } else {
        traverseLeft(root->right, ans);
    }
}


void traverseLeaf(node* root, vector<int>& ans) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}


void traverseRight(node* root, vector<int>& ans) {
    if ((root == NULL) || (root->left == NULL && root->right == NULL)) {
        return;
    }
    if (root->right) {
        traverseRight(root->right, ans);
    } else {
        traverseRight(root->left, ans);
    }
    ans.push_back(root->data);
}


vector<int> boundaryTraversal(node* root) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }
    ans.push_back(root->data);

    // left part store
    traverseLeft(root->left, ans);

    // traverse leaf node
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);

    // traverse right part
    traverseRight(root->right, ans);

    return ans;
}


node* buildTreeFromVector(vector<int>& data, int& index) {
    if (index >= data.size() || data[index] == -1) {
        index++;
        return NULL;
    }
    node* root = new node(data[index++]);
    root->left = buildTreeFromVector(data, index);
    root->right = buildTreeFromVector(data, index);
    return root;
}


void inorder(node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main() {
    vector<int> data = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
//     1
//     / \
//    3   5
//   / \  /
//  7  11 17

    int index = 0;
    node* root = buildTreeFromVector(data, index);

    cout << "Inorder traversal is: ";
    inorder(root);
    cout << endl;

    vector<int> boundary = boundaryTraversal(root);
    cout << "Boundary traversal is: ";
    for (int val : boundary) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
