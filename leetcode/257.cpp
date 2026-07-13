#include "include.h"



  struct TreeNode {
     int val;
    TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        /*
        i will add to result if left and right return null
        after completion fo stack frame pop fromcurrent

        */
        vector<int> current;
        vector<string> result;
        TreeNode* n = solve(root, current, result);
        return result;

    }

    TreeNode* solve(TreeNode* root, vector<int>& current, vector<string>& result) {
        if (!root) return nullptr;
        current.push_back(root->val);
        TreeNode* left = solve(root->left, current, result);
        TreeNode* right = solve(root->right, current, result);
        if (!left && !right) {
            string temp = "";
            for (int i = 0; i < current.size(); i++) {
                if (i == 0) {
                    temp += to_string(current[i]);
                } else {
                    temp += "->" + to_string(current[i]);
                }
            }
            result.push_back(temp);
        }
        current.pop_back(); 
        return root;
    }
};



// cleaneer solution
void dfs(TreeNode* node, string path, vector<string> result) {
    if (!node->left && !node->right) {
        result.push_back(path);
        return;
    }
    if (node->left) dfs(node->left, path + "->" + to_string(node->left->val), result);
    if (node->right) dfs(node->right, path + "->" + to_string(node->right->val), result);
}