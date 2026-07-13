// Detect cycles in an undirected graph
#include <vector>
#include <queue>
using namespace std;

class Solution {
    private:
        bool solve(int V, vector<vector<int>>& adj, int i, vector<bool> &visited) {
            queue<pair<int, int>> q; // {node, parent}
            q.push({i, -1});
            while (!q.empty()) {
                auto [node, parent] = q.front();
            q.pop();
                for (int neighbour : adj[node]) {
                    if (!visited[neighbour]) {
                    q.push({neighbour, node});
                    visited[neighbour] = true;
                    }
                    else if (neighbour != parent) return true;
                }
            }
            return false;



        }

    public:
        bool is_cycle(int V, vector<vector<int>> adj) {
            vector<bool> visited(V, false);
            for (int i = 0; i < V; i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    if (solve(V, adj, i,  visited)) return true;
                }
            }
            return false;
        }

};