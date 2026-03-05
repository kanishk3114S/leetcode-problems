class Solution {
public:
    int minOperations(string s) {
    
   
    string a="";
    string b="";

    for (int i=0; i<s.length(); i=i+2) {

        if (i == s.length()) {

            a+='0';
            b+= '1';
            break;

        }
        a += '0';
        a+= '1';

        b+= '1';
        b+='0';    

    }

    int cnt1 = 0 , cnt2 = 0;

    for (int i=0; i<s.length(); i++) {

        if (a[i] != s[i]) cnt1++;
        if (b[i] != s[i]) cnt2++;

    }

    return min(cnt1 , cnt2);




    }
};