class Solution {
public:
    long long gcdSum(vector<int>& nums) {

    vector<long long> mx;
    long long maxel = INT_MIN;
    for(int i=0; i<nums.size(); i++) {

        maxel = max(maxel , (long long) nums[i]);
        mx.push_back(maxel);

    }

    vector<long long> p_gcd;
    int val = 0;
    for (int i=0; i<nums.size(); i++) {

        val = gcd(nums[i] , mx[i]);
        p_gcd.push_back(val);

    }

    sort(p_gcd.begin() , p_gcd.end());
    int mid = 0;
    mid = p_gcd.size()/2;
    
    long long l = 0 , r = p_gcd.size()-1;
    long long sum = 0;
    while (l < r) {

        sum += gcd(p_gcd[l] , p_gcd[r]);
        l++;
        r--;

    }

    return sum;


    }
};