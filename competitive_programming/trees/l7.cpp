

#include "tree.h"
#include <algorithm>
/*

Diameter of a binary tree is the length between two nodes and the path(length) does not need to pass through the root


  
 */


 int diameter(TreeNode* node, int& maxi) {
    if (!node) return 0;
    int left = diameter(node->left, maxi);
    int right = diameter(node->right, maxi);
    maxi = std::max(maxi, left + right);
    return 1 + std::max(left, right);
 }

 int find_diameter(TreeNode* node) {
    int dia = 0;
    diameter(node, dia);
    return dia;
 }