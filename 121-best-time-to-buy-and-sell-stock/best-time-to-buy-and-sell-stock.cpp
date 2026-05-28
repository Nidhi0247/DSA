class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit=INT_MIN;
        for(int i =0;i<prices.size();i++){
            if(prices[i]<minprice){
                minprice = prices[i];
            }
            maxprofit = max(maxprofit,prices[i]-minprice);
        }

        if(maxprofit == INT_MIN) return 0;
        return maxprofit;
    }
};