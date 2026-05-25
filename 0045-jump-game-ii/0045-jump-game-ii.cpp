class Solution {
public:
    int jump(vector<int>& arr) {
        

        int n = arr.size();

        queue<int>q;
        q.push(0);

        int t = 0;
        vector<bool> hash(n);
        int farthest = 0;

        while (!q.empty()) {

            int size = q.size();

            for (int i=0; i<size; i++) {
                
                int idx = q.front();

                if (idx == n-1) return t;

                q.pop();

                int mini = max(idx , farthest+1);
                int maxi = min(idx+arr[idx] , n-1);

                for (int id=mini; id<=maxi; id++) {

                    if (id==n-1) return t+1;

                    if (!hash[id]) {
                        q.push(id);
                        hash[id] = true;
                    }

                }

                farthest = maxi;


            }

            t++;

        }

        return t;

    }
};