class Solution {
public:

    bool iseven(int n) {
        return n % 2 == 0;
    }

    vector<int> sortArrayByParityII(vector<int>& arr) {

        int even = 0, odd = 1;
        int n = arr.size();

        while (even < n && odd < n) {

            while (even < n && iseven(arr[even]))
                even += 2;

            while (odd < n && !iseven(arr[odd]))
                odd += 2;

            if (even < n && odd < n)
                swap(arr[even], arr[odd]);
        }

        return arr;
    }
};