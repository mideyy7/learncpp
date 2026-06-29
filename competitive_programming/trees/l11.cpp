

#include <vector>
#include "tree.h"

bool check(TreeNode* left, TreeNode* right) {
    if (!left || !right) {
        return left == right;
    }
    if (left->value != right->value) return false;
    return check(left->left, right->right) && check(left->right, right->left);
}

bool is_symmetric(TreeNode* root) {
    return !root || check(root->left, root->right);
}


bool solve(TreeNode* root, int value, std::vector<int> & result) {
    if (!root) return false;
    result.push_back(root->value);
    if (root->value == value) return true;
    if (solve(root->left, value, result) || solve(root->right, value, result)) return true;
    result.pop_back();
    return false;
}

std::vector<int> get_path(TreeNode* root, int value) {
    std::vector<int> result;
    if (!root) return result;
    solve(root, value, result);
    return result;
}
