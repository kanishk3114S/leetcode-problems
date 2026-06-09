class ProductOfNumbers {
    vector<__int128> vec;
    __int128 prod;
    int lastzero = -1;
    const __int128 MOD = 1e9+7;
public:
    ProductOfNumbers() {
        prod = 1;
    }
    
    void add(int num) {
        if (num==0) {
            num = 1;
            lastzero = vec.size();
            prod = 1;
        }
        prod *= num;
        // prod=(prod%(MOD));
        vec.push_back(prod);
    }
    
    int getProduct(int k) {

        int size = vec.size();
        if (k==size && lastzero == -1) return vec[size-1];
        if (lastzero >= size-k) return 0;

        __int128 ans = vec[size-1]/vec[size-k-1];

        return (int)ans;

    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */