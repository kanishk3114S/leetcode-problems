class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        priority_queue<pair<int,int>> pq; //maxheap//
        
        
        for (int i=0; i<k; i++) {
            pq.push({arr[i] , i});
        }
        
        
        int l = 0 , r = k-1;
        
        while (r < n) {
            
            while (!pq.empty() && pq.top().second < l) {
                pq.pop();
            }
            
            ans.push_back(pq.top().first);
            
            l++;
            r++;
            if (r == n) break;
            pq.push({arr[r] , r});
        
            
        }
        
        return ans;
    }
};