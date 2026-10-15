class Solution {
public:
    bool checkpalin(string & s ,int i,int j){

        while(i<j) {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int getans(string & s,int i,vector<int> & dp){
        if(dp[i]!=-1) return dp[i];
        int n = s.size();
        if(i==n || checkpalin(s,i,n-1) ) return dp[i]= 0;
       

        int mini=INT_MAX;
        for(int k=i;k<n;k++){
            if(checkpalin(s,i,k)){
               int cost= 1 + getans(s,k+1,dp);
                mini=min(mini,cost);
            }
        }
        return dp[i]=mini;

    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return getans(s,0,dp);
    }
};