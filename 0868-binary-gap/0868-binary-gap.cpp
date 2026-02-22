class Solution {
public:
    int binaryGap(int n) {
        if ((n & (n-1)) == 0) return 0;
        int bit = 0;
        int streak = 0 , maxstreak = 0;
        vector<int> indi;
        for (int i=0; i<32; i++) {
            bit = (n>>i) & 1;

            if (bit == 1) {
                indi.push_back(i);
            }
        }

        for (int i=indi.size()-1; i>0; i--) {
            maxstreak = max(maxstreak , indi[i]-indi[i-1]);
        } 

        return maxstreak;


    }
};