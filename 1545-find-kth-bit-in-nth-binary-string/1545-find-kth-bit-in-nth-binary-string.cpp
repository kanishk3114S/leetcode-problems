class Solution {
public:
    char findKthBit(int n, int k) {
        //optimised solution//
        //since Sn = Sn-1 + '1' + reverse(invert(Sn-1))//

        if (n==1) return '0'; //if recursive calls

        // we knoe if k==mid --> 1 else > mid ......... //

        int len = (1<<n)-1;
        int mid = (len+1)/2;

        if (k == mid) return '1';
         if (k < mid) return findKthBit(n-1,k); //it will get shot .. check short again//
         

            int mirrored = len-k+1;
            char bit = findKthBit(n-1 , mirrored);

            return bit=='0' ? '1' : '0';



    }
};