class Solution {
public:
    bool isGood(vector<int>& arr) {
        multiset<int>s;
        //fit the bases in the s//
        int cnt =0;
        for (int num:arr){
            s.insert(num);
            if (num==arr.size()-1) cnt++;
        }

        for (int i=1; i<=arr.size()-1; i++) {

            //these are the values we need to check the basis for//

            if (!s.count(i)) return false;
            else s.erase(i);

        }

        return s.size()==0 && cnt==2;

    }
};