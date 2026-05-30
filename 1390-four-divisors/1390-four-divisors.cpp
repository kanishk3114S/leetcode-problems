class Solution {
public:

    bool isprime(int n) {

        for (int i=2; i<=sqrt(n); i++) {

            if (n%i == 0) return false;

        }

        return true;

    }

    long long sieve(long long n) {

        long long cnt = 0;
        bool found = false;

        for (int i=2; i<=sqrt(n); i++) {

            if (n%i == 0 && !found) {
                 long long other = n/i;
                 if (other != i) {
                 cnt = other+i+1+n;
                 found = true;
                 } 
            } else if (n%i == 0 && found) return 0;

        }

        return found == true ? cnt : 0;

    }

    int sumFourDivisors(vector<int>& nums) {

        //6 --> first composite to have more than 4 factors//

        long long ans = 0;

        for(int i=0; i<nums.size(); i++) {

            if (nums[i] >= 6 && !isprime(nums[i])) {

                ans += sieve((long long)nums[i]);
                // cout << nums[i] << " " << sieve((long long)nums[i]) << endl;

            }

        }

        return (int)ans;

    }
};