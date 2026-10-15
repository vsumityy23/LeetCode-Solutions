class Solution {
public:
    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(V);
        vector<int> dist(V,INT_MAX);
        dist[src]=0;

        for(auto & edge : flights ){

            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({v,w});
 
        }

        queue<pair<int,int>> q;
        q.push({src,0});

        int ans=INT_MAX;

        for(int i=0;i<k+2;i++){

            int l=q.size();

            while(l--){

                int u=q.front().first;
                int d=q.front().second;
                q.pop();
                if(u==dst) ans=min(ans,d);
                for(auto &  x : adj[u]){
                    
                    int v=x.first;
                    int wt=x.second;
                if(wt+d<dist[v]){
                    q.push({v,wt+d});
                    dist[v]=wt+d;
                    }
                }
            }


        }
        if(ans==INT_MAX) ans=-1;

        return ans;
       
    }
};