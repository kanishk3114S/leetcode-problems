class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        // int even_min = INT_MIN , odd_min = INT_MIN;
        set<int> even , odd;
        int oddcnt = 0 , evencnt = 0;

        for (int i=0; i<nums.size(); i++) {

            if (i%2 == 0) {
                // even_min = min(even_min , abs(nums[i]%k));
                even.insert(nums[i]%k);
                evencnt++;
            } else {
                // odd_min = min(odd_min , abs(nums[i]%k));
                odd.insert(nums[i]%k);
                oddcnt++;
            }
            
        }

        //now we have to inc the elements by 1...and deacres the element  by 1..//

        unordered_map<int,int> even_cost , odd_cost;
        
        int minops = INT_MAX;
        for (auto it:even) {

            //for every even indices//

            int r = it;
            int ops = 0;
        
            for (int i=0; i<nums.size(); i=i+2) {

            int cur = nums[i] % k;

            int add = abs(cur-r);   // move forward
            int sub = k-abs(cur-r); // move backward
            
            ops += min(add, sub);    
            }
            even_cost[it] = ops;   
            minops = min(ops , minops);
            
        }
        int minops2 = INT_MAX;
        for (auto it:odd) {

            //for every even indices//

            int r2 = it;
            int ops2 = 0;
        
            for (int i=1; i<nums.size(); i=i+2) {

            int cur2 = nums[i] % k;

            int add2 = (r2 - cur2 + k) % k;   // move forward
            int sub2 = (cur2 - r2 + k) % k;   // move backward
            
            ops2 += min(add2, sub2);  
                
            }
            odd_cost[it] = ops2;
            minops2 = min(ops2 , minops2);
            
        }

        int mincost = INT_MAX;
        
        for (auto it:even_cost) {
            for (auto it2:odd_cost) {

                if (it.first != it2.first) {
                    mincost = min(mincost , it.second+it2.second);
                }
                
            }
        }

        if (mincost == INT_MAX) {
            return min(evencnt , oddcnt);
        }

        return mincost;
        
    }
};