class Solution {
public:

    string invert(string s) {

        for (int i=0; i<s.length(); i++) {

            if (s[i] == '1') s[i] = '0';
            else s[i] = '1';

        }

        return s;

    }

    string reverseS(string s) {

        int l = 0 , r = s.length()-1;
        while (l<=r) {
            swap(s[l] , s[r]);
            l++;
            r--;
        }
        return s;

    }

    string func(int n) {

        if (n == 1) return "0";

        return  func(n-1) + "1" + reverseS((invert(func(n-1))));     

    }

    char findKthBit(int n, int k) {
        
        string s = "";
        s = func(n);

        return s[k-1];


    }
};