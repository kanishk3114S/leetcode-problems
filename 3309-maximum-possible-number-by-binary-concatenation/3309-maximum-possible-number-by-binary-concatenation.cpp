class Solution {
public:
    int maxGoodNumber(vector<int>& arr) {
        
        vector<string> binary;
        string bin ="";

        for (int i=0; i<arr.size(); i++) {
            bin = "";
            while (arr[i] > 0) {

                bin += (arr[i]%2)+'0';
                arr[i]/=2;

            }
            reverse(bin.begin() , bin.end());
            binary.push_back(bin);

        }

        long long ans = 0, pow = 1;
        long long maxans = 0;


        for (int i=0; i<6; i++) {

            next_permutation(binary.begin() , binary.end());
            string resultant = "";
            ans = 0 , pow = 1;
            for (int i=0; i<binary.size(); i++) {

                resultant += binary[i];
            
            }

            for (int i=resultant.length()-1; i>-1; i--) {
                if (resultant[i] == '1') {
                    ans+= pow;
                }
                pow *= 2;
            }

            maxans = max(maxans , ans);

        }

        return maxans;


    }
};