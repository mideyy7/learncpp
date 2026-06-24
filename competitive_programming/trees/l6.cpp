
#include <queue>
#include "tree.h"

int max_depth(TreeNode* root) {
    int result = 0;
    std::queue<TreeNode*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        size_t size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front(); q.pop();
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        result++;
    }
    return result;
}

int max_depth_2(TreeNode* root) {
    if (!root) return 0;
    int left_height = max_depth_2(root->left);
    int right_height = max_depth_2(root->right);
    return 1 + std::max(left_height, right_height);
}

bool is_balanced(TreeNode* root) {
    if (!root) return true;
    int left_height = max_depth_2(root->left);
    int right_height = max_depth_2(root->right);
    if (std::abs(left_height - right_height) > 1) return false;
    bool left = is_balanced(root->left);
    bool right = is_balanced(root->right);
    return left && right;
}

int balanced(TreeNode* root) {
    if (!root) return 0;
    int left_height = balanced(root->left);
    if (left_height == -1) return -1;
    int right_height = balanced(root->right);
    if (right_height == -1) return -1;
    if (std::abs(left_height - right_height) > 1) return -1;
    return 1 + std::max(left_height, right_height);
}