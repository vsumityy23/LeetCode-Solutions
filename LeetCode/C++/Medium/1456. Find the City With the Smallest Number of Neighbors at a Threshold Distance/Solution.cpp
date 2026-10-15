class Solution {
public:
void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n=dist.size();
        
        for(int k=0;k<n;k++){
            
            for(int i=0;i<n;i++){
                
                for(int j=0;j<n;j++){
                    
                    if( dist[i][k]!=1e8 && dist[k][j]!=1e8 && dist[i][k]+dist[k][j]<dist[i][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                    
                }
            }
            
            
            
        }
        
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e8));

            for(int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

        for(auto &edge:edges ){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            dist[u][v]=wt;
            dist[v][u]=wt;
        }

        floydWarshall(dist);

        int ans_dist=INT_MAX;
        int node=-1;

        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if( dist[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<ans_dist){
                ans_dist=count;
                node=i;
            }
            else if (count==ans_dist) node=max(node,i);
        }

        return node;
        
    }
};