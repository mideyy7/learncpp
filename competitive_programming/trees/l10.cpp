

#include <queue>
#include <vector>
#include "tree.h"

/*
right view
do level order traversal
append right to queue before left
on each pop from queue add to result

*/

std::vector<int> right_view(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        size_t dim = 
    }


}