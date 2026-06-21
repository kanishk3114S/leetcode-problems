class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        //using the counting sort//

        int maxval = INT_MIN;

        for (auto it:costs) {
            maxval = max(maxval ,it);
        }

        vector<int> freq(maxval+1);

        for (int i=0; i<costs.size(); i++) {

            freq[costs[i]]++;

        }

        int idx = 0;

        for (int i=0; i<freq.size(); i++) {

            if (freq[i] > 0) {
                
                for (int j=0; j<freq[i]; j++) {

                    costs[idx++] = i;

                }

            }

        }

        for (int i=0; i<costs.size(); i++) {

            if (costs[i] > coins) return i;

            coins -= costs[i];

        }

        return costs.size();

    }
};