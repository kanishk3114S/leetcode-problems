class Solution {
public:

    bool check(vector<int>& piles , long long h , long long k) {

        for (int i=0; i<piles.size(); i++) {

            long long bananas = piles[i];
            long long spent = (bananas+(k-1))/k;

            h-= spent;

            if (h < 0) return false;

        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        long long sum = 0;
        for (auto it:piles) sum+=it;

        long long low = 1 , high = sum;
        long long ans = sum;

        while (low <= high) {

            long long mid = low-(low-high)/2;

            if (check(piles,h,mid)) {
                ans = mid;
                high = mid-1;
            } else{ 
                low = mid+1;
            }


        }

        return ans;
        

    }
};