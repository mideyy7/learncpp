#include <vector>
#include <stack>

using namespace std;



/*

========================TOPOLOGICAL SORT========================================
*/
class Solution {
public:
    vector<int> topo_sort(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, st, adj);
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }

    void dfs(int node, vector<int>& visited, stack<int>& st, vector<int> adj[]) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, visited, st, adj);
            }

        }
        st.push(node);

    }


};