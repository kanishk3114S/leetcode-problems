class Solution {
public:

    int solver(int n , int k , int curr , int start , int end , int currLevel) {

        if (currLevel == n) return curr;

        long long mid = start+(end-start)/2;

        if (k <= mid) {

            if (curr == 0) {
                return solver(n,k,0,start,mid,currLevel+1);
            } else {
                return solver(n,k,1,start,mid,currLevel+1);
            }
        } else {
            
            if (curr == 0) {
                return solver(n,k,1,mid+1,end,currLevel+1);
            } else {
                return solver(n,k,0,mid+1,end,currLevel+1);
            }
        }

        return 0;

    }

    int kthGrammar(int n, int k) {
        
        long long total = pow(2,n-1);

        return solver(n,k-1,0,0,total-1,1);

    }
};