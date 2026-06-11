class Solution {
public:

    void solver(vector<vector<int>>& adj ,vector<vector<int>>&ans , vector<bool>&vis , vector<int> temp , int node , int n) {

        if (node == n-1) {
            temp.push_back(node);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }

        temp.push_back(node);
        vis[node] = true;

        for (int i=0; i<adj[node].size(); i++) {

            int nbr = adj[node][i];

            if (!vis[nbr]) {
                solver(adj,ans,vis,temp,nbr,n);
            }

        }

        vis[node]=false;
        temp.pop_back();


    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        
        int n = adj.size();

        vector<bool> vis(n,false);
        vector<vector<int>> ans;
        vector<int> temp;

        solver(adj , ans , vis , temp , 0 , n);

    return ans;


    }
};