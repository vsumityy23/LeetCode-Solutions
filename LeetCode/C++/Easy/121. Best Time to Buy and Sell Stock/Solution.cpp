class Solution {
public:
    int maxProfit(vector<int>& arr) {
        
        
        int n=arr.size();
        int buy=arr[0];
        int profit=0;

        for(int i=1;i<n;i++){
            buy=min(buy,arr[i]);
            int sell=arr[i];
            profit=max(profit,sell-buy);

        }

        return profit;
    }
};