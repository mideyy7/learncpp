
#include <iostream>
#include <queue>


#include "tree.h"

// note best practice is to use if (!node) instead of if (node == nullptr)

void pre_order(TreeNode* node) {
    if (node == nullptr) return;
    std::cout << node->value << ' '; 
    pre_order(node->left);
    pre_order(node->right);
}

void in_order(TreeNode* node) {
    if (node == nullptr) return;
    in_order(node->left);
    std::cout << node->value << ' ';
    in_order(node->right);
}

void post_order(TreeNode* node) {
    if (node == nullptr) return;
    post_order(node->left);
    post_order(node->right);
    std::cout << node->value << ' ';
}

void level_order(TreeNode* node) {
    if (node == nullptr) return;
    std::queue<TreeNode* > q;
    q.push(node);
    while (!q.empty()) {
        int dim = q.size();
        for (int i = 0; i < dim; i++) {
            TreeNode* node = q.front();
            q.pop();
            std::cout << node->value << ' ';
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }

    }


}