#include <iostream>
#include<vector>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void inorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void levelOrderTraversal(node *root){
    vector<vector<int>> ans;
    if (!root) return;

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    vector<int> v;

    while (!q.empty()) {
        node *temp = q.front();
        q.pop();

        if (temp == NULL) {
            // End of level
            ans.push_back(v);
            v.clear();
            cout << endl;

            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            v.push_back(temp->data);

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}

int main()
{

    node *root = NULL;
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    // creating a Tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "inorder traversal is:  ";
    inorder(root);

    cout << "level order traversal is:  ";
    levelOrderTraversal(root);

    return 0;
}