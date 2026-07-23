/*

Minimum Spanning Tree

A spanning tree has n nodes and n - 1 edges
minimum spanning tree is a spanning tree with minimum total weight


Disjoint Set

Prism's Algotithm

0- Start with a node
- get the shortest wight from that node that has not been cisited and mark it as visited
- move to that node and repeat

*/

#include "include.h"

void prism(vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col ){
    int rows = grid.size();
    int cols = grid[0].size();
    // weight , node, parent
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0,0-1});
    while (!pq.empty()) {
        vector<int> v = pq.top(); pq.pop();
        
    }



}