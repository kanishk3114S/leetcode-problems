class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<long long , greater<long long>> s;

        for (int i=0; i<nums.size(); i++) s.insert(nums[i]);

        if (s.size() < 3) {
            return *s.begin();
        } else {

            while (s.size() > 3) {

                s.erase(prev(s.end()));
            }

        }
        return *prev(s.end());
    }
};