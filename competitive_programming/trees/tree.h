#pragma once



struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int value) : TreeNode(value, nullptr, nullptr) {}
    TreeNode(int value, TreeNode* left, TreeNode* right): value(value), left(left), right(right) {}
};