#include <vector>



struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int value) : TreeNode(value, nullptr, nullptr) {}
    TreeNode(int value, TreeNode* left, TreeNode* right): value(value), left(left), right(right) {}
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    // include <memory> to use auto new_node = std::make_unique<TreeNode>(4);
    return 0;
}

