class Solution {
public:
    
    vector<string> st;

    void build(int node, int l, int r, vector<string>& arr) {

        if (l == r) {
            st[node] = arr[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid, arr);
        build(2 * node + 1, mid + 1, r, arr);

        st[node] = st[2 * node] + st[2 * node + 1];
    }

    string intToRoman(int num) {

        vector<string> ones = {
            "", "I", "II", "III", "IV",
            "V", "VI", "VII", "VIII", "IX"
        };

        vector<string> tens = {
            "", "X", "XX", "XXX", "XL",
            "L", "LX", "LXX", "LXXX", "XC"
        };

        vector<string> hundreds = {
            "", "C", "CC", "CCC", "CD",
            "D", "DC", "DCC", "DCCC", "CM"
        };

        vector<string> thousands = {
            "", "M", "MM", "MMM"
        };

        vector<string> arr(4);

        arr[0] = thousands[num / 1000];
        arr[1] = hundreds[(num / 100) % 10];
        arr[2] = tens[(num / 10) % 10];
        arr[3] = ones[num % 10];

        st.resize(16);

        build(1, 0, 3, arr);

        return st[1];
    }
};