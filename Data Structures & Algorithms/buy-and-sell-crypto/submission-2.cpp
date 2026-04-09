class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int buyPrice = prices[0];

        for(int &x : prices){
            if(buyPrice > x) buyPrice = x;
            maxProfit = max(maxProfit, x - buyPrice);
        }

        return maxProfit;
    }
};
