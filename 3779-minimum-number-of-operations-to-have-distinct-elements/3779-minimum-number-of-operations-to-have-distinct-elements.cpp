class Solution {
public:
    int minOperations(vector<int>& arr) {
        
        unordered_map<int,int> mpp;
        for (int i=0; i<arr.size(); i++) {
            mpp[arr[i]]++;
        }
        int dup = 0;

        for (auto i:mpp) {
            if (i.second > 1) dup++;
        }

        //now duplicates contains the no of unique elements//

        //for the rest of the array to contain only the unique elements dup == 0//

        if (dup == 0) return 0;
        int cnt = 0;

        cout << dup << endl;

        for (int i=0; i<arr.size(); i=i+3) {

            for (int j=0; j<3; j++) {

                
                mpp[arr[i+j]]--;
                if (mpp[arr[i+j]] == 0) {
                    mpp.erase(arr[i+j]);
                } else if (mpp[arr[i+j]] == 1) {
                    dup--;
                }

                if (mpp.empty()) break;

            }

            cout << dup << endl;
            cnt++;

            if (dup == 0) break;

        }

        return cnt;



    }
};