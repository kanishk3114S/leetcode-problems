class Solution {
public:
    int nthUglyNumber(long long n) {
        
        set<long long> s;

        long long curr = 0;
        s.insert(1);
        while (curr != n) {
            auto it = s.begin();
            advance(it, curr);
            s.insert(*it*2);
            s.insert(
                *it*3);
            s.insert(*it*5);
            curr++;
        }

    auto it = s.begin();
    advance(it, curr-1);

    return *it;

    }
};