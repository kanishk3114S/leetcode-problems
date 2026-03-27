class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& list1, vector<vector<int>>& list2) {
        
        vector<vector<int>> result;

        int l = 0 , r = 0;
        int start = 0 , end = 0;

        if (list1.size() == 0 || list2.size() == 0) return result;

        while (l<list1.size() && r<list2.size()) {

            if (list1[l][1] >= list2[r][0] && list1[l][0] <= list2[r][1]) {
                //then that means there is an intersection//

                start = max(list1[l][0] , list2[r][0]); //the min of both startings//
                end = min(list1[l][1] , list2[r][1]);

                result.push_back({start , end});

                list1[l][1] > list2[r][1] ? r++ : l++;
                // cout << list1[l][1] << " " << list2[r][1];

            } else { //in case of no overlapping//

                list1[l][0] > list2[r][0] ?  r++ : l++;

            }

        }

        return result;

        

    }
};