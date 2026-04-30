class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& arr) {
        vector<int> prefix;
        vector<int> suffix;

        long long psum = 0 , ssum = 0;
        for(int i=0; i<arr.size(); i++) {

            psum += arr[i];
            prefix.push_back(psum);

        }
        for (int i=arr.size()-1; i>-1; i--) {
            ssum +=arr[i];
            suffix.push_back(ssum);
        }

        reverse(suffix.begin() , suffix.end());

        vector<int> ans;

        for (int i=0; i<arr.size(); i++) {

            long long left = i==0 ? 0 : (1LL*i*arr[i]) - prefix[i-1];
            long long right = i==arr.size()-1 ? 0 : suffix[i+1] - (1LL*(arr.size()-i-1)*arr[i]);

            ans.push_back(left+right);

        }

        return ans;

        


    }
};