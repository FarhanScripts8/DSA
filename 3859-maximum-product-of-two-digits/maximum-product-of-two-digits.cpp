class Solution {
public:
    int maxProduct(int n) {
        int firstMax = -1;   // largest digit
        int secondMax = -1;  // second largest digit

        while (n > 0) {
            int d = n % 10;  // current digit
            n /= 10;

            if (d > firstMax) {
                // shift previous firstMax down to secondMax
                secondMax = firstMax;
                firstMax = d;
            } else if (d > secondMax) {
                secondMax = d;
            }
        }

        return firstMax * secondMax;
    }
};