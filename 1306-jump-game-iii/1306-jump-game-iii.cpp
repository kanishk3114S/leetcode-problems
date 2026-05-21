class Solution {
public:

    void dfs(vector<int> adj[] , vector<int>&vis , int node , set<int>&zeroset , bool&ans) {

        vis[node] = true;
        if (zeroset.count(node)) ans = true;

        for (int i=0; i<adj[node].size(); i++) {

            if (!vis[adj[node][i]]) {
                dfs(adj , vis , adj[node][i] , zeroset , ans);
            }

        }

    }

    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        vector<int> vis(n);
        vector<int> adj[n+1];

        int reachnode = 0;
        set<int> zeroset;
        for (int i=0; i<arr.size(); i++) {
            if(arr[i] == 0){zeroset.insert(i);}
        }

        for (int i=0; i<n; i++) {

            int left = i-arr[i];
            int right = i+arr[i];

            if (left > -1) {
                adj[i].push_back(left);
            }
            if (right < n) {
                adj[i].push_back(right);
            }

        }

        bool ans = false;

        dfs(adj , vis , start , zeroset , ans);

        return ans;

    }
};