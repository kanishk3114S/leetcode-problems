class Solution {
public:


    int calc(vector<int>&arr) {
        int len = arr.size();
        vector<int> ns;
        stack<int> s;
        for (int i=arr.size()-1; i>-1; i--) {

            if (s.empty()) {
                ns.push_back(len);
            } else {

                if(arr[i] > arr[s.top()]) { 
                    ns.push_back(s.top());
                } else {

                    while(!s.empty() && arr[s.top()] >= arr[i]) {
                        s.pop();
                    }
                    
                    if (s.empty()) ns.push_back(len);
                    else ns.push_back(s.top());

                }
            }
            s.push(i);

        }

        reverse(ns.begin() , ns.end());
        int area = 0 , maxarea = INT_MIN;
        int width = 0;
        for (int i=0; i<arr.size(); i++) {
            width = ns[i]-i;
            area = arr[i]*width;

            maxarea = max(area , maxarea);

        }

        return maxarea;

    }


    int largestSubmatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> prefgrid (m , vector<int>(n));

        //calculate the prefix grid..using the column wise traversal//

        for (int j=0; j<n; j++) {
            vector<int> temp;
            int streak = 0;
        
            for (int i = 0; i<m; i++) {

                if (mat[i][j] == 1) {
                    streak++;
                } else {
                    streak = 0; 
                }

                prefgrid[i][j] = streak;

            }
        } 

        //got the prefix grid..//

        int ans = INT_MIN;

        for (int i=0; i<m; i++) {
            sort(prefgrid[i].begin() , prefgrid[i].end());
            
            ans = max(ans , calc(prefgrid[i]));

        }

        return ans;

    }
};