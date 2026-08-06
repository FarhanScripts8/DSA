class Solution {
public:
    int smallestNumber(int n, int t) {
        auto digitProduct = [](int x) {
            int prod = 1;
            if (x == 0) return 0;          // not needed for constraints, but safe
            while (x > 0) {
                int d = x % 10;
                prod *= d;
                x /= 10;
            }
            return prod;
        };

        // Constraints guarantee answer exists soon (n <= 100, t <= 10) [page:40]
        int x = n;
        while (true) {
            int prod = digitProduct(x);
            if (prod % t == 0) return x;
            ++x;
        }
    }
};