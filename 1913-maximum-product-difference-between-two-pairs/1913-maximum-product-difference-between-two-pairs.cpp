class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        
      int maxi = INT_MIN , mini = INT_MAX;
      int maxi2 = maxi , mini2 = mini;

      for (int num:nums) {

        if (num > maxi) {
            maxi2 = maxi; //before updating the maxi make maxi2 --> before maxi//
            maxi = num;
        } else if (num>maxi2) {
            maxi2 = num;
        }

        if (num < mini) {
            mini2 = mini;
            mini = num;
        } else if (num < mini2) {
            mini2 = num;
        }

      }

      return (maxi*maxi2)-(mini*mini2);

    }
};