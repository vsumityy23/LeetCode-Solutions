class Solution {
public:
  
  void addedge( vector<vector<int>> & adj,int i,int j){
     
      adj[j].push_back(i);
  }
    bool canFinish(int V, vector<vector<int>>& edges) {

           vector<vector<int>> adj(V);
      
        
        for(int i=0;i<edges.size();i++){
            addedge(adj,edges[i][0],edges[i][1]);
        }
        
        
        vector<int> indegree(V,0);
        
      for(int i=0;i<V;i++){
          for(int x:adj[i]){
              indegree[x]++;
          }
      }
      
      
      
      queue<int> q;
      
      
      for(int i=0;i<V;i++){
          if(indegree[i]==0){
              q.push(i);
          }
      }
          
          
          while(!q.empty()){
              int node=q.front();
              q.pop();
           
              
              for(int x : adj[node]){
                  
                  indegree[x]--;
                  if(indegree[x]==0){
                      q.push(x);
                      
                  }
              }
              
              
          }
      
      
      
      for(int i=0;i<V;i++){
          if(indegree[i]) return false;
      }
      
      return true;
        
        
    }
};