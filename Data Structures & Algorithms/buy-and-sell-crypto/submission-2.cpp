class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        int i = 0;
        while(i<n){
            int j = i+1;
            while( j<n && prices[i]<prices[j]){
                profit = max(profit,prices[j] -prices[i]);
                j++;

            }

            i = j;
        }

    return profit;
    }
};
