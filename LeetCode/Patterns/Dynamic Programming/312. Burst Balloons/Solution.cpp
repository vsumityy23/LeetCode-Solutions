class Solution {
public:
    int f(vector<int> & nums,vector<vector<int>> & dp,int i,int j){
        
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
                   
         int mini=INT_MIN;          
        for(int k=i;k<=j;k++){
            int cost = nums[i-1]*nums[k]*nums[j+1] + f(nums,dp,i,k-1) + f(nums,dp,k+1,j);
            mini=max(mini,cost);
        }

        return dp[i][j]=mini;

    }
    int maxCoins(vector<int>& nums) {
        

       
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n =nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(nums,dp,1,n-2);
    }
};