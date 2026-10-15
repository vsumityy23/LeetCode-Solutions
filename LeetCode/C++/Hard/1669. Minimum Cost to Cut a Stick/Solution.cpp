class Solution {
public:
    int f(vector<int>&cuts,vector<vector<int>>&dp,int i,int j){

        if(dp[i][j]!=-1) return dp[i][j]; 

        int mini=INT_MAX;
        for(int ind=i+1;ind<j;ind++) {
         
                int cost=cuts[j]-cuts[i] + f(cuts,dp,i,ind) + f(cuts,dp,ind,j);
                mini=min(mini,cost);

        }

        if(mini==INT_MAX) return dp[i][j]=0;

        return dp[i][j]=mini;

    }
    int minCost(int n, vector<int>& cuts) {

        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int m=cuts.size();

        vector<vector<int>> dp(m,vector<int>(m,-1));
        return f(cuts,dp,0,m-1);
        
    }
};