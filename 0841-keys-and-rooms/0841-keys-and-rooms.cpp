class Solution {
public:
    void dfs(vector<vector<int>>& adj , vector<bool>&vis, int idx) {

        vis[idx] = true;
        // ans.push_back(idx);
        for (int i=0; i<adj[idx].size(); i++) {

            if (!vis[adj[idx][i]]) {
                dfs(adj , vis  , adj[idx][i]);
            } 

        }

    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        vector<bool> vis(n);
        int cnt = 0;
        for(int i=0; i<vis.size(); i++) {
            if (!vis[i]) {
                cnt++;
                dfs(rooms , vis , vis[i]);
            }
        }

        return cnt<=1;
        
    }
};