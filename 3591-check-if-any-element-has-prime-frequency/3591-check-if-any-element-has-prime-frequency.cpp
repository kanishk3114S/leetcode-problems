class Solution {
public:

    bool isprime(int n) {

        if (n == 1) return false;

        for (int i=2; i<=sqrt(n); i++) {

            if (n%i == 0) return false;

        }

        return true;

    }

    bool checkPrimeFrequency(vector<int>& arr) {
        
        unordered_map<int,int> mpp;

        for(int val:arr) mpp[val]++;

        for (auto it:mpp) {

            if (isprime(it.second)) return true;

        }

        return false;

    }
};