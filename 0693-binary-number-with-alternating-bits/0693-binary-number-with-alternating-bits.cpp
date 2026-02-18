class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int bitone = 0 , bittwo = 0;
        bool onefound = false;
        int correctidx = 0;

        for (int i=0; i<31; i++) {

            correctidx = 31-i;

            bitone = ((n>>correctidx) & 1);
            bittwo = ((n>>(correctidx-1)) & 1);

            if (bitone == 1) onefound = true; 

            if (onefound == true && bitone == bittwo) return false;

        }

        return true;

    }
};