

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