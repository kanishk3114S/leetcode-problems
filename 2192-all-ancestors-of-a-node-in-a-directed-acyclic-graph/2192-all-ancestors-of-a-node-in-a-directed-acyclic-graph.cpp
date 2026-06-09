class Solution {
public:

    void dfs(vector<int> adj[] , vector<bool>&vis , int node , vector<int>&temp , int source) {

        vis[node] = true;
        if (node != source) {

            temp.push_back(node);

        }

        for (int i=0; i<adj[node].size(); i++) {

            if (!vis[adj[node][i]]) {
            dfs(adj,vis,adj[node][i],temp,source);
            }

        }

    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n];

        for (int i=0; i<edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[v].push_back(u);

        }

        // unordered_map<int,vector<int>> mpp; //storing the ancestors for the given edges//

        // for (int i=0; i<n; i++) {

        //     int node = i;

        //     for (int j=0; j<adj[node].size(); j++) {

        //         int nbr = adj[node][j];

        //         mpp[nbr].push_back(node);
            
        //     }

        // }
        
        vector<vector<int>> ans(n);

        for (int i=0; i<n; i++) {
            vector<int> temp;
            vector<bool> vis(n,false);
            dfs(adj , vis , i , temp , i);
            sort(temp.begin() , temp.end());
            ans[i] = temp;
        }

        return ans;
    }
};