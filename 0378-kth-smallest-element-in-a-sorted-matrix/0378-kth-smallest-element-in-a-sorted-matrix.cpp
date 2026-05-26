class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        using ppi = pair<int,pair<int,int>>;
        priority_queue<int> pq;
        multiset<ppi> s;
        vector<vector<bool>> vis(n , vector<bool>(n,false));

        int row = 0 , col = 0;
        pq.push(matrix[0][0]);
        vis[row][col] = true;
        int el1 = 0 , el2 = 0;
        int scan = 1;
        while(scan < k) {
        if (s.size() != 0) {

            auto it = s.begin();

            row = it->second.first;
            col = it->second.second;        
            s.erase(s.begin());
            scan++;
        }

        if (row+1 < n && !vis[row+1][col]) {

        el1 = matrix[row+1][col];
        pq.push(el1);
        vis[row+1][col] = true;
        s.insert({el1 , {row+1 , col}});

        }

        if (col+1 < n && !vis[row][col+1]) {

            el2 = matrix[row][col+1];
            pq.push(el2);
            vis[row][col+1] = true;
            s.insert({el2,{row,col+1}});

        }

        }

        while (pq.size() > k) {
            pq.pop();
        }

        // while (!pq.empty()) {
        //     cout << pq.top() << " ";
        //     pq.pop();
        // }

        return pq.top();

    }
};