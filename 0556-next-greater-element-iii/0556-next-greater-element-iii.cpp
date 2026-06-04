class Solution {
public:
    int nextGreaterElement(int n) {
        
        long long num = n;
        vector<long long> temp;
        while (num > 0) {

            temp.push_back(num%10);
            num/=10;

        }

        reverse(temp.begin() , temp.end());
        next_permutation(temp.begin() , temp.end());
        string s ="";
        for (int num:temp){

            s += to_string(num);

        }

        // cout << s;

        num = stoll(s);

        cout << num-n;

        if (num <= n || num > INT_MAX) return -1;

        return num;

    }
};