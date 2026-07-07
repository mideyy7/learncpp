

#include <queue>
#include <vector>
#include "tree.h"

/*
right view
do level order traversal
append right to queue before left
on each pop from queue add to result

*/

std::vector<int> right_view(TreeNode* root) {
    std::vector<int> result;
    std::queue<TreeNode*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        size_t dim = q.size();
        for (size_t i = 0; i < dim; i++) {
            TreeNode* node = q.front(); q.pop();
            if (i == 0) result.push_back(node->value);
            if (node->right) q.push(node->right);
            if (node->left) q.push(node->left);
        }
     }
     return result;
}


std::vector<int> left_view(TreeNode* root) {
    std::vector<int> result;
    std::queue<TreeNode*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        size_t dim = q.size();
        for (size_t i = 0; i < dim; i++) {
            TreeNode* node = q.front(); q.pop();
            if (i == 0) result.push_back(node->value);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return result;
}

