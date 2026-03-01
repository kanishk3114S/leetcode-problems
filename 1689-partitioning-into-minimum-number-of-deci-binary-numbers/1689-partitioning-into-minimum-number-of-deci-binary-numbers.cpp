class Solution {
public:
    int minPartitions(string n) {
        //for every n digit number......you will subtract 1..11 (till n)//
        //therfore ones the ones part is gone then the tens part will etting subtract//
        int ans = 0;
       
        for (int i=n.length(); i>-1; i--) {

            ans = max(ans , n[i]-'0');

        }

        return ans;


    }
};