class Solution {
public:



    int getans(vector<vector<int>>& arr,int i,int j,vector<vector<int>>& dp,int m){
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1) return dp[i][j]=arr[i][j];

        

        int dx[]={1,1};
        int dy[]={0,1};

        int cost=INT_MAX;
        for(int k=0;k<2;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
                int steps=arr[i][j]+getans(arr,nx,ny,dp,m);
                cost=min(steps,cost);
        }
        return dp[i][j]=cost;

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n =triangle.size();
     vector<vector<int>> dp(n, vector<int>(n, 0));

        // Initialize the last row of dp with triangle values
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        // Traverse from second-last row to the top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                // Calculate sum from down and diagonal paths
                int down = triangle[i][j] + dp[i + 1][j];
                int diag = triangle[i][j] + dp[i + 1][j + 1];

                // Store the minimum of the two paths
                dp[i][j] = min(down, diag);
            }
        }

        // Return the minimum path sum from top
        return dp[0][0];
    }
};