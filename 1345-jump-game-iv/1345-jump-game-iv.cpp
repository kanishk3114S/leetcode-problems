class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        unordered_map<int,vector<int>> mpp; //indi -> indi//

        for (int i=0; i<arr.size(); i++) {

            mpp[arr[i]].push_back(i);

        }


        queue<int> q;
        vector<bool> hash(n);
        vector<bool>scanning(n);

        q.push(0);
        hash[0] = true;
        int t = 0;

        while (!q.empty()) {

            int size = q.size();

            for (int i=0; i<size; i++) {

                int idx = q.front();
                q.pop();
                int mini = max(idx-1 , 0);
                int maxi = min(idx+1 , n-1);

                if (idx == n-1) return t;
                if (maxi == n-1) return t+1;

                if (!hash[mini]) {
                    q.push(mini);
                    hash[mini] = true;
                }
                if (!hash[maxi]) {
                    q.push(maxi);
                    hash[maxi] = true;
                }

                if (!scanning[idx]) {
                for (int it=mpp[arr[idx]].size()-1; it>-1; it--) {

                    if (mpp[arr[idx]][it] == n-1) return t+1;
                    scanning[mpp[arr[idx]][it]] = true;

                    if (!hash[mpp[arr[idx]][it]]) {
                        q.push(mpp[arr[idx]][it]);
                        hash[mpp[arr[idx]][it]] = true;
                    }

                }
                scanning[idx] = true;
                }



            }

            t++;

        }

        return t;

    }
};