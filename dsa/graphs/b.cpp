



class Solution {

    public:
        vector<int> topo (int V, vector<int> adj[]) {
            vector<int> vis(V, 0);
            stact<int> st;
            for(int i = 0; i < V; i++) {
                if (!vis[i]) {
                    dfs(i, st, vis, adj);
                }
            }

            vector<int> result;
            while (!st.empty()) {
                result.push_back(st.top());
                st.pop();
            }
            return result;
        }

        void dfs(int node, stack<int>& st, vector<int>& vis, vector<int> adj[]) {
            vis[node] = 1;
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    dfs(it, st, vis, adj);
                }
            }
            st.push(node);
        }

};