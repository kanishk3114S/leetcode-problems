class Solution {
public:
    bool isBalanced(string s) {

    int oddsum = 0 , evensum = 0;

    for (int i=0; i<s.length(); i++) {

        if (i%2 == 0) evensum += s[i]-'0';
        else oddsum += s[i]-'0';

    }

    return evensum==oddsum;

    }
};