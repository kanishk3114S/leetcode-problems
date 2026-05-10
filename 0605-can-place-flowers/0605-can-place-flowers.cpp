class Solution {
public:

    bool left(vector<int>& flowerbed , int idx) {

        if (idx==0) return true;

        return flowerbed[idx-1] == 0; 

    }

    bool right(vector<int>& flowerbed , int idx) {

        if (idx == flowerbed.size()-1) return true;

        return flowerbed[idx+1] == 0;

    }

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        for (int i=0; i<flowerbed.size(); i++) {
            
            if (flowerbed[i] == 0 && left(flowerbed , i) && right(flowerbed, i)) {

                n--;
                flowerbed[i] = 1;

            }

        }

        if (n>0) return false;

        return true;
    }
};