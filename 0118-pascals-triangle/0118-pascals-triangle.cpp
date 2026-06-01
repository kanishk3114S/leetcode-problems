class Solution {
  public:
  
  void solver(vector<int>&arr , vector<int>&next ,  int size , int n , vector<vector<int>>&ans) {
      
      if (size == n+1) return;
      
      //calls//
      
      next.resize(size);
      
      next[0] = 1;
      next[size-1] = 1;
      
      int ptr = 1;
      for (int i=0; i<arr.size()-1; i++) {
          
          next[ptr] = arr[i]+arr[i+1];
          ptr++;
          
      }
      arr = next;
      ans.push_back(next);
      solver(arr , next , size+1 , n , ans);
      
  }
  
  
    vector<vector<int>> generate(int n) {
        // code here
        
        if (n == 1) return {{1}};
        
        vector<int>arr(1);
        vector<int> next;
        vector<vector<int>> ans;
        ans.push_back({1});
        solver(arr , next , 2 , n , ans);
        
        return ans;
        
        
    }
};
