class Solution {
public:

    void dfs(int node , vector<int> adj[] , vector<bool>&vis) {

        vis[node] = true;
        for (int i=0; i<adj[node].size(); i++) {

            if (!vis[adj[node][i]]) {
                dfs(adj[node][i] , adj , vis);
            }

        }

    }

    int findCircleNum(vector<vector<int>>& mat) {
        
        int n = mat.size();
        vector<int> adj[n+1];
        vector<bool> vis(n+1);

        for (int i=0; i<mat.size(); i++) {

            for (int j=0; j<mat[0].size(); j++) {

                if (mat[i][j] == 1) {

                    adj[i+1].push_back(j+1);

                }

            }

        }

        int cnt = 0;

        for (int i=1; i<vis.size(); i++) {

            if (!vis[i]) {
                cnt++;
                dfs(i , adj , vis);
            }

        }

        return cnt;

    }
};