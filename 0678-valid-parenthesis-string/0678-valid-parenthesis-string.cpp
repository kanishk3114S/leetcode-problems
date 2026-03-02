class Solution {
public:
    bool checkValidString(string s) {
        
        //for every '*' .. we will maintain the minimum possible answer and maximum possible answer//

        int min = 0 , max = 0;

        for (char ch:s) {

            if (ch == '(') {
                min++;
                max++;
            } else if (ch == ')') {
                min--;
                max--;
            } else { //asteric founded//
                
                min--;
                max++;

            }
        if (min < 0 && max >=0) min = 0;
        if (max < 0) return false; //till that ppint the max is negative.....tf its not possible..

        }

        return min==0;

    }
};