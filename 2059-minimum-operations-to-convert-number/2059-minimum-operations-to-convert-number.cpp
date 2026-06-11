class Solution {
public:
    int minimumOperations(vector<int>& arr, int start, int goal) {
        
        queue<int> q;
        // q.push(start);
        // unordered_map<int,bool> vis;

        vector<bool> vis(1001,false);

        q.push(start);
        vis[start] = true;
        int moves = 0;

        while (!q.empty()) {

            int size = q.size();

            for (int i=0; i<size; i++) {

                int num = q.front();
                q.pop();
                if (num == goal) return moves;

                if (num >= 0 && num <= 1000) {
                    for (int j=0; j<arr.size(); j++) {

                    int el1 = num+arr[j];
                    int el2 = num-arr[j];
                    int el3 = num^arr[j];

                    // cout << el1 << " " << el2 << " " << el3 << endl;

                    if (el1 == goal || el2 == goal || el3 == goal) return moves+1;

                    if (el1>=0 && el1<=1000 && !vis[el1]) {
                        q.push(el1);
                        vis[el1] = true;
                    } else if (el1<0 || el1>1000) {
                        q.push(el1);
                    }
                    if (el2>=0 && el2<=1000 && !vis[el2]) {
                        q.push(el2);
                        vis[el2] = true;
                    } else if (el2 < 0 || el2 > 1000){
                        q.push(el2);
                    }
                    if (el3>=0 && el3<=1000 && !vis[el3]) {
                        q.push(el3);
                        vis[el3] = true;
                    } else if (el3 < 0 || el3 > 1000){
                        q.push(el3);
                    }
                }

                // cout << num << " ";

            }
            }
            // cout << endl;
            moves++;
        }

        return -1;


    }
};