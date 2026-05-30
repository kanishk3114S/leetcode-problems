class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        
        vector<bool> sieve(1e6+1 , false);

        sieve[1] = true;

        for (int i=2; i<=sqrt(1e6); i++) {

            if (!sieve[i]) {

                for (int j=i*i; j<=(1e6); j=j+i) {

                    sieve[j] = true;

                }

            }

        }

        int first = -1;
        int diff = INT_MAX;
        int a = -1 , b = -1;

        for (int i=left; i<=right; i++) {
            
            if (!sieve[i]) {
                cout << i << " ";
                if (first != -1) {
                    if (i-first < diff) {
                        diff = i-first;
                        a = first;
                        b = i;
                    }

                } 
                first = i;
            }

        }

        return {a,b};

    }
};