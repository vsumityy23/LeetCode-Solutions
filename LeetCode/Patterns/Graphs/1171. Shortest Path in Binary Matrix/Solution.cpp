class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {

        int n=mat.size();

        if(mat[0][0]==1 || mat[n-1][n-1]==1) return -1;

        if(n==1){
            if(mat[0][0]==1) return -1;
            else return 1;
                return -1;
            
        }
      
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        queue <pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=true;

        int dist=1;

        int dx[]={0,0,1,-1,1,1,-1,-1};
        int dy[]={1,-1,0,0,1,-1,1,-1};
        



        while(!q.empty()){

            int k=q.size();
            dist++;
            

            while(k--){

            int x=q.front().first;
            int y=q.front().second;
            

            
            q.pop();

             for(int i=0;i<8;i++){

                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx==n-1 && ny==n-1) return dist;

                if(nx>=0 && nx<n && ny>=0 && ny<n && mat[nx][ny]==0 &&!vis[nx][ny]){
                        q.push({nx,ny});
                        vis[nx][ny]=true;
                }
            }


            }
            
        }

        return -1;


        
    }
};