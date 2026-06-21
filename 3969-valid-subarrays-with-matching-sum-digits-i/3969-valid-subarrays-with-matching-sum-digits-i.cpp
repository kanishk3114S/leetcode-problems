class Solution {
public:

    bool check(long long n , int x) {

        if (n==x) return true;

        // string s = to_string(n);
        // char ch = x+'0';

        // if (s[0] == ch && s[s.length()-1] == ch) return true;

        // return false;

        int lastdig = n%10;

        while (n>=10) {
            n/= 10;
        }
        if (n==x && lastdig == x) return true; 

        return false;

    }

    int countValidSubarrays(vector<int>& arr, int x) {
        
        int ans = 0;
        for (int i=0; i<arr.size(); i++) {
        long long sum = 0;
            for (int j=i; j<arr.size(); j++) {

                sum += (long long)arr[j];

                if (check(sum , x)) {
                    ans++;
                    // cout << " for sum : " << sum << " ans is : " << ans <<endl; 
                }

                // cout << i << "  " << j << " " << " sum : " <<sum << " ans : " <<ans <<  endl;
                
                

            }

        }

        return ans;

    }
};