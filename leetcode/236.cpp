#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val, Node* left = nullptr, Node* right = nullptr) : val(val), left(left), right(right) {}
};




int main() {
    int x;
    vector<int> v;
    while (cin >> x) {
        v.push_back(x);
    }
    Node* prev = nullptr;
    for (int i = v.size() - 1; i >= 0; i--) {
        Node* curr = Node(v[i]);
        if (prev) curr->left = prev;
        prev = curr;
    }
    lca(prev, p,q);
}



Node* lca(Node* root, int p, int q) {
    if (!root || root->val == p || root->val == q) return root;
    Node* left = lca(root->left, p, q); 
    Node* right = lca(root->right, p, q);
    if (left && right) return root;
    return (left ? left : right);
}