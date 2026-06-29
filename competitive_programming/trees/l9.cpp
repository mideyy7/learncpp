

#include <vector>
#include <map>
#include <utility>
#include <queue>

#include "tree.h"


/*

perform a level order traversal going level by level
for left -> +1,,,,,,, for right -> -1
add to the queue.... (node, position)
pop from the queue and check if it exists in map
if not exit add to map: if it exusts skip
iterate through map and pick values

*/

std::vector<int> top_view(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;

    std::map<int, int> mp;
    std::queue<std::pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        size_t dim = q.size();
        for (size_t i = 0; i < dim; i++) {
             auto [node, position] = q.front(); q.pop();
            if (mp.find(position) == mp.end()) {
                mp[position] = node->value;
            }
            if (node->left) q.push({node->left,position - 1});
            if (node->right) q.push({node->right, position + 1});
        }
    }

    for (const auto& [position, value]: mp) {
        result.push_back(value);
    }
    return result;
}

/*
Bottom View

Go through the tree by level order traversal
in the queue.. push {node, position}
if left child exists: posiion - 1, if right child exists position +1
after pop from queue update the position in map
*/

std::vector<int> bootom_view(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;

    std::map<int, int>mp;
    std::queue<std::pair<TreeNode*,int>>q;
    q.push({root,0});

    while (!q.empty()) {
        auto [node, position] = q.front(); q.pop();
        mp[position] = node->value;
        if (node->left) q.push({node->left, position - 1});
        if (node->right) q.push({node->right, position + 1});
    }

    for (const auto& [position, value] : mp){
        result.push_back(value);
    }
    return result;



}