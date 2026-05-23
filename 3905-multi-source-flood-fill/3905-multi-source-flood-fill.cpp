class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        
        sort(sources.begin() , sources.end() , [](const vector<int>&a , const vector<int>&b) {
            
            return a[2] > b[2];

        });

        vector<vector<int>> grid(n,vector<int>(m , 0));

        for (auto it:sources) {

            grid[it[0]][it[1]] = it[2];

        }

        queue<vector<int>> q;

        for (int i=0; i<sources.size(); i++) {
            q.push(sources[i]);
        }

        while (!q.empty()) {

            int size = q.size();

            for (int i=0; i<size; i++){
            int sr = q.front()[0];
            int sc = q.front()[1];
            int color = q.front()[2];
            q.pop();

            if (sc != 0 && grid[sr][sc-1] == 0){
                grid[sr][sc-1] = color;
                q.push({sr,sc-1,color});
            }
            if (sr != 0 && grid[sr-1][sc] == 0){
                grid[sr-1][sc] = color;
                q.push({sr-1,sc,color});
            }
            if (sc != m-1 && grid[sr][sc+1] == 0){
                grid[sr][sc+1] = color;
                q.push({sr,sc+1,color});
            }
            if (sr != n-1 && grid[sr+1][sc] == 0){
                grid[sr+1][sc] = color;
                q.push({sr+1 , sc , color});
            }
            }


        }

        return grid;

    }
};