class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int i = 0, maxProfit = 0;
        for(int j = 1; j < n; j++){
            int profit = prices[j] - prices[i];

            if(profit <= 0){
                i = j;
                continue;
            }

            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};
