class Solution {
public:
    int countDigits(int num) {
        unordered_map<int,int> mpp;
        int temp = num;
        int digit = 0;
        while (temp > 0) {
            digit = temp%10;
            mpp[digit]++;         
            temp/=10;
        }

        int cnt = 0;

        for (auto it:mpp) {

            if (num%it.first == 0) cnt += mpp[it.first];
            else continue;

        }

        return cnt;

    }
};