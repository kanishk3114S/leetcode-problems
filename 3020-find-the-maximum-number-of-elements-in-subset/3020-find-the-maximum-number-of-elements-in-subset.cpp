class Solution {
public:

    /*
    
    x , x2 , x4 , xpeak , xpeak/2 xpeak/2......;
    so its like peak....for every x another x should exists
    
    */

    int maximumLength(vector<int>& arr) {
        
        using ld = long double;

        unordered_map<ld,ld> mpp;

        for (auto it:arr) {
            mpp[(long double)it]++;
        }

        unordered_set<int> check;


        int ans = 0;

        for (auto it:mpp) {

            int seq = 0;
            int el = it.first;  

            if (el==1 || check.count(el)) continue;
            int times = 1;
                while (seq < arr.size()) {
                    long double val = pow(el , times);
                    if (mpp.count(val) && mpp[val] >= 2) {
                        seq++;
                        times = times*2;
                    } else if (mpp.count(val) && mpp[val] < 2) {
                        
                        //we found our peak;
                        seq++;
                        check.insert(el);
                        break;

                    } else {
                        check.insert(el);
                        break;
                    }
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