

#include <algorithm>
#include <vector>
#include <queue>
#include "tree.h"



int max_path_sum(TreeNode* node, int& max_sum) {
    if (!node) return 0;
    int left_sum = std::max(0, max_path_sum(node->left, max_sum));
    int right_sum = std::max(0, max_path_sum(node->right, max_sum));
    max_sum = std::max(max_sum, node->value + left_sum + right_sum);
    return node->value + std::max(left_sum, right_sum);
}


std::vector<std::vector<int>> zig_zag(TreeNode* node, std::vector<std::vector<int>>& result) {
    if (!node) return result;
    std::queue<TreeNode*> q;
    bool flag = true;
    q.push(node);
    while (!q.empty()) {
        size_t length = q.size();
        std::vector<int> temp_arr(length);
        for (int i = 0; i < length; i++) {
            TreeNode* curr = q.front(); q.pop();
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
            if (flag) {
                temp_arr[i] = curr->value;
            } else {
                temp_arr[length - i - 1] = curr->value;
            }
        }
        flag = !flag;
        result.push_back(temp_arr);
    }
    return result;
}

/*
Boundary traversal
->  ANTICLOCKWISE: left boundary then leaf nodes then right boundary in reverse
-> CLOCKWISE: right boundary then leaf nodes then left boundary in reverse
-> use pre order trsversal to get the leaf nodes

*/
bool is_leaf(TreeNode* node) {
    return (!node->left && !node->right);
}
void add_left_boundary(TreeNode* root, std::vector<int>& res) {
    TreeNode* node = root->left;
    while (node) {
        if (!is_leaf(node)) res.push_back(node->value);
        if (node->left)  {
            node = node->left;
        } else {
            node = node->right;
        }
     }
}

void add_leaves(TreeNode* node, std::vector<int>& res) {
    if (!node) return;
    if (is_leaf(node)) res.push_back(node->value);
    add_leaves(node->left, res);
    add_leaves(node->right, res);
}

void add_right_boundary(TreeNode* root, std::vector<int>& res) {
    TreeNode* node = root->right;
    std::vector<int> temp;
    while (node) {
        temp.push_back(node->value);
        if (node->right) {
            node = node->right;
        } else {
            node = node->left;
        }
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        res.push_back(temp[i]);
    }
}

std::vector<int> anti_clockwise_boundary(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;
    if (!is_leaf(root)) result.push_back(root->value);
    add_left_boundary(root, result);
    add_leaves(root, result);
    add_right_boundary(root, result);
    return result;
}