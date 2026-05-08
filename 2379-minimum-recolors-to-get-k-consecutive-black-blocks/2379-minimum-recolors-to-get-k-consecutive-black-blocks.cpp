class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int times = blocks.length()-k+1;
        int cnt,mincnt= INT_MAX;
        for (int idx=0; idx < times; idx++) {
            cnt = 0;
            for (int i=idx; i<(idx+k); i++) {

                //for each window//
                // cout << i << " ";
                if (blocks[i] == 'W') cnt++;

            }

            // cout << endl;
            // cout << idx << " " << cnt << " ";

            mincnt = min(mincnt , cnt);

            // cout << mincnt;
            // cout << endl;

        }

        return mincnt;


    }
};