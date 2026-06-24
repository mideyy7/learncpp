
#include <vector>
#include <stack>
#include <algorithm>
#include "tree.h"

// Iterative DFS Traversals

// Pre order Traversal
/*
    put root in stack
    put root->right in stack
    put root->left in stack
    at each iteration print what is at the top of the stack
*/

// In Order Traversal
/*
    go as far down as you can left and push to stack
    pop from stack and change curr to right and repeat
    important loop condotion : while (curr || !stack.empty())
*/

//Post Order Traversal
/*
    2 Techniques
    1. Do pre order and reverse
    2. Use 2 stacks.... conditions for each is while(!stack.empty())
        a. push root to stack 2(pop from 1), left, right to stack 1 in one loop
        b. pop from stack 2 intor result in one loop

*/

std::vector<int> pre_order(TreeNode* node) {
    std::vector<int> result;
    if (!node) return result;
    std::stack<TreeNode*> stack;
    stack.push(node);
    while (!stack.empty()) {
        TreeNode* curr = stack.top();
        stack.pop();
        result.push_back(curr->value);
        if (curr->right) stack.push(curr->right);
        if (curr->left) stack.push(curr->left);
    }
    return result;
}


std::vector<int> in_order(TreeNode* node)
 {
    std::vector<int> result;
    std::stack<TreeNode* > st;
    TreeNode* curr = node;
    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        result.push_back(curr->value);
        curr = curr->right;
    }
    return result;
 }

 std::vector<int> post_order(TreeNode* node) {
    std::vector<int> result;
    if (!node) return result;
    std::stack <TreeNode*> st;
    st.push(node);
    while (!st.empty()) {
        TreeNode* curr = st.top(); st.pop();
        result.push_back(curr->value);
        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }
    std::reverse(result.begin(), result.end());
    return result;
 }


 /*
    Combining all traversals in one loop
    pseudo:

    if num == 1:
        pre.add(node.value)
        num++
        push left
    elif num == 2:
        in.add(node.value)
        num++
        push right
    else:
        post.add(node.value)
 
 
 */