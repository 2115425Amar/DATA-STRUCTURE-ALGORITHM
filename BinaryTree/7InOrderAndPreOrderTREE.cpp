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

int find(vector<int> &inorder, int element, int n){
    for(int i=0; i<n; i++){
        if(inorder[i] == element){
            return i;
        }
    }
    return -1; // Added return statement to avoid warning
}

node *solve(vector<int> &inorder, vector<int> &preorder, int &index, int inStart, int inEnd, int n){
    if(index >=n || inStart > inEnd){
        return NULL;
    }
    
    int element = preorder[index++];
    node *root = new node(element);
    
    int pos = find(inorder, element, n);
   
    root->left = solve(inorder, preorder, index, inStart, pos-1, n);
    root->right = solve(inorder, preorder, index, pos+1, inEnd, n);
    
    return root;
}

node *buildTree(vector<int> &inorder, vector<int> &preorder) {
    int n = preorder.size();
    int index = 0;
    node * ans = solve(inorder, preorder, index, 0, n-1, n);
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

    cout << "Inorder traversal of tree built from vector is: ";
    inorder(root);
    cout << endl;

    vector<int> inorderTraversal = {7, 3, 11, 1, 17, 5};
    vector<int> preorderTraversal = {1, 3, 7, 11, 5, 17};

    node* rootFromInPre = buildTree(inorderTraversal, preorderTraversal);

    cout << "Inorder traversal of tree built from inorder and preorder is: ";
    inorder(rootFromInPre);
    cout << endl;

    return 0;
}
