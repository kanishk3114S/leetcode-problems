class Solution {
public:

    /*
    
    x , x2 , x4 , xpeak , xpeak/2 xpeak/2......;
    so its like peak....for every x another x should exists
    
    */

    int maximumLength(vector<int>& arr) {
        
        using ll = long long;

        unordered_map<ll,ll> mpp;

        for (auto it:arr) {
            mpp[(long long)it]++;
        }

        int ans = 0;

        for (auto it:mpp) {

            int seq = 0;
            int el = it.first;  

            if (el==1) continue;
            long long curr = el;
                while (seq < arr.size()) {
                    if (mpp.count(curr) && mpp[curr] >= 2) {
                        seq++;
                        curr = curr*curr;
                    } else if (mpp.count(curr) && mpp[curr] < 2) {
                        
                        //we found our peak;
                        seq++;
                        break;

                    } else {
                        break;
                    }
                    // cout << curr << " " << seq << endl; 
                }

                ans = max(seq , ans);

        }

        // cout << ans;

        if (ans > 1) {

            ans += (ans-1);

        }

        int one_freq = mpp[1];

        if ((long long)mpp[1]%2 == 0) {
            one_freq = mpp[1]-1;
        } 

        ans = max(ans , one_freq);

        return ans;

    }
};