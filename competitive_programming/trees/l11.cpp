

#include <vector>
#include <queue>
#include <utility>
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


// revise this one and know what to do if both/one of a and b are absent in the tree
TreeNode* lowest_common_ancestor(TreeNode* root, TreeNode* a, TreeNode* b) {
    if (!root || root == a || root == b) return root;
    TreeNode* left = lowest_common_ancestor(root->left, a, b);
    TreeNode* right = lowest_common_ancestor(root->right, a, b);
    if (!left) return right;
    if (!right) return left;
    return root;
}

int max_width(TreeNode* root) {
    int right = INT_MAX;
    int left = INT_MIN;
    std::queue<std::pair<TreeNode* ,int>> q;
    if (!root) return 0;
    q.push({root, 0});
    while (!q.empty()) {
        auto [node, position] = q.front(); q.pop();
        int right = std::min(right, position);
        int left = std::max(left, position);
        if (node->left) q.push({node->left, position + 1});
        if (node->right) q.push({node->right, position - 1});
    }
    return left - right;
    
}

