class Solution {
public:
    int getLength(vector<int>& arr) {

        int maxlen = INT_MIN;
        
        for (int i=0; i<arr.size(); i++) {
            unordered_map<int,int> freq;
            unordered_map<int,int> cnt;
            for (int j=i; j<arr.size(); j++) {

                int old = freq[arr[j]];

                if (old > 0) {
                    cnt[old]--;
                    if (cnt[old] == 0)
                        cnt.erase(old);
                }

                freq[arr[j]]++;
                cnt[freq[arr[j]]]++;

                if (freq.size() == 1) {
                    maxlen = max(maxlen , j-i+1);
                } else if (cnt.size() == 2) {
                    auto it = cnt.begin();
                    int k1 = it->first;

                    ++it;
                    int k2 = it->first;
                
                    if ((k1 > k2 && k1 == 2*k2) || (k2>k1 && k2 == 2*k1)) {
                        maxlen = max(maxlen , j-i+1);
                    }
                } else {
                    continue;
                }



            }
        }

        return maxlen;

    }
};