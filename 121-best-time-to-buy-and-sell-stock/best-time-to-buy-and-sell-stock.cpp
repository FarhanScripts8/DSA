class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min = INT_MAX;

        int max_profit = 0;
        for(int i=0; i<n; i++){
            if(prices[i]<min) min = prices[i];

            max_profit= max(max_profit, prices[i]-min);
        }
        return max_profit;
    }
};