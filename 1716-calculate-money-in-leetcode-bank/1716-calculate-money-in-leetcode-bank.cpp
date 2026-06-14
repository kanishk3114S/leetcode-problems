class Solution {
public:
    int totalMoney(int n) {
        
        int Monday = 0;
        int i = 1;

        int sum = 0 , add = 1;

        while (i <= n) {

        sum += (add + Monday);
        add++;

        if (i%7 == 0) {
            Monday++;
            add = 1;
        }
        i++;

        }

        return sum;

    }
};