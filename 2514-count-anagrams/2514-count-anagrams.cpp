class Solution {
public:

    const long long MOD = 1e9 + 7;

        long long factorial(int n) {
            long long fact = 1;

            for (int i = 2; i <= n; i++) {
                fact = (fact * i) % MOD;
            }

            return fact;
        }
        long long power(long long a, long long b) {
            long long res = 1;

            while (b) {
                if (b & 1)
                    res = (res * a) % MOD;

                a = (a * a) % MOD;
                b >>= 1;
            }

            return res;
        }

        long long modInverse(long long x) {
            return power(x, MOD - 2);
        }

    int countAnagrams(string s) {
        
        vector<string> vec;
        string temp = "";

        for (char ch:s) {

            if (ch == ' ') {
                vec.push_back(temp);
                temp="";
            } else {
                temp += ch;
            }
        }

        vec.push_back(temp);

        long long ans = 1;

        for (int i=0; i<vec.size(); i++) {

            string t = vec[i];
            long long fc = factorial(t.length());
            unordered_map<char,long long> freq;
            for (char ch:t) {
                freq[ch]++;
            }
            for(auto it:freq) {

                if (freq[it.first] > 1) {

                    fc = (fc * modInverse(factorial(it.second))) % MOD;

                }

            }
            ans = (ans * fc) % MOD;        
        }

        return (int)ans;

    }
};