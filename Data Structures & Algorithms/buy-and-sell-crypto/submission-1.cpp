class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int i = 0, j = 1, maxProfit = 0, curProfit = 0;
        
        while(j < n){
            if(prices[i] >= prices[j]) i = j;
            else{
                curProfit = prices[j] - prices[i];
                maxProfit = max(maxProfit, curProfit);
            }
            
            j++;
        }
        
        return maxProfit;
    }
};
