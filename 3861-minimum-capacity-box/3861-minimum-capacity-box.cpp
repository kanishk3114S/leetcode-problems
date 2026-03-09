class Solution {
public:
    int minimumIndex(vector<int>& cap, int lim) {
        
        int minel = INT_MAX , minidx = -1;

        for (int i=cap.size()-1; i>-1; i--) {


            if (cap[i] >= lim && cap[i] <= minel) {

                minel = cap[i];
                minidx = i;

            }

        }

        return minidx;


    }
};