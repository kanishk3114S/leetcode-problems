class Solution {
public:
    int minimumOperationsToMakeEqual(int ex, int y) {
        
        if (y >= ex) return y-ex;

        vector<bool> vis(1e4+1 , false);

        queue<int>q;
        q.push(ex);

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            for (int i=0; i<sz; i++) {

            int x = q.front();
            // cout << x << " ";
            q.pop();
            if (x==y) return moves;

            if (x%11 == 0 && !vis[x/11]) {
                q.push(x/11);
                vis[x/11]  = true;
            } 
            if (x%5 == 0 && !vis[x/5]) {
                q.push(x/5);
                vis[x/5] = true;
            } 
            if (x > 0 && x < vis.size() && !vis[x-1]) {
                q.push(x-1);
                vis[x-1] = true;
            } 
            if (x < vis.size() && !vis[x+1]) {
                q.push(x+1);
                vis[x+1] = true;
            }
            
            }

            // cout<<endl;

            moves++;

        }

        return moves;

    }
};