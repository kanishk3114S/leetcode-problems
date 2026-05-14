class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin() , pairs.end() , [](const vector<int>&a , const vector<int>&b){

            return a[1] < b[1]; 

        });

        int chain_cnt = 1;
        int endline = pairs[0][1];

        // for (int i=0; i<pairs.size(); i++) {

        //     cout << pairs[i][0] << " " << pairs[i][1] << endl;

        // }

        for (int i=1; i<pairs.size(); i++) {

            if (pairs[i][0] <= endline) {

                continue;

            } else {

                endline = pairs[i][1];
                chain_cnt++;
                cout << "occured " << endl;

            }

        }

        return chain_cnt;

        

    }
};