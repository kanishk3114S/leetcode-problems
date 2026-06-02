class Solution {
public:

    bool bfs(vector<vector<int>>& adj , vector<int>& vis , int color , int source) {

        queue<pair<int,int>> q;
        q.push({source , color});

        while (!q.empty()) {

            int size = q.size();

            for (int i=0; i<size; i++) {

                int node = q.front().first;
                int nodeclr = q.front().second;
                q.pop();

                for (int idx = 0; idx < adj[node].size(); idx++) {

                    if (vis[adj[node][idx]] == nodeclr) return false;
                    
                    if (vis[adj[node][idx]] == -1) {
                        if (nodeclr == 0) {
                            vis[adj[node][idx]] = 1;
                            q.push({adj[node][idx] , 1});
                        } else {vis[adj[node][idx]] = 0;
                        q.push({adj[node][idx] , 0});}
                    }

                }


            }

        }
        return true;

    }

    bool isBipartite(vector<vector<int>>& adj) {
        
        vector<int> vis(adj.size() , -1);
        for (int i = 0; i < adj.size(); i++) {
                if (vis[i] == -1) {
                    vis[i] = 0;
                    if (!bfs(adj, vis, 0, i))
                        return false;
                }
            }
            return true;
    }
};