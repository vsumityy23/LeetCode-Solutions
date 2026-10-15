class Solution {
public:

    int  chalmc(int i,int j, int m, int n,vector < vector<int>> & dp){

        //maa chud gyi
        if(i>m || j>n){
            return 0;
        } 

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        //phuch gya bc
        if(i==m && j==n){
            return dp[i][j]=1;
        }

        

        
        int right = chalmc(i,j+1,m,n,dp);
        int down = chalmc(i+1,j,m,n,dp);
        

        return dp[i][j]=right + down;
      
        
    }

    int uniquePaths(int m, int n) {
        
        vector < vector<int>> dp(m,vector<int>(n,-1));
        return chalmc(0,0,m-1,n-1,dp);
        
    }
};