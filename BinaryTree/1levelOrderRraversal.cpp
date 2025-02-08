#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @class Solution
 * @brief This class provides a solution to perform level order traversal on a binary tree.
 * 
 * The levelOrder function takes the root of a binary tree and returns a vector of vectors,
 * where each inner vector contains the values of the nodes at each level of the tree.
 */
class Solution {
public:
    /**
     * @brief Performs level order traversal on a binary tree.
     * 
     * This function takes the root of a binary tree and returns a vector of vectors,
     * where each inner vector contains the values of the nodes at each level of the tree.
     * 
     * @param root The root node of the binary tree.
     * @return A vector of vectors containing the values of the nodes at each level.
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp->val);

                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Create a Solution object
    Solution solution;
    vector<vector<int>> result = solution.levelOrder(root);

    // Print the result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up the allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}