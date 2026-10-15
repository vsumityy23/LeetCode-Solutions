class Solution {
public:
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void dfs(vector<vector<int>>& adj, vector<bool>& visited, int s) {
    visited[s] = true;
    for (int i : adj[s]) {
        if (!visited[i]) {
            dfs(adj, visited, i);
        }
    }
}

    int getComponents(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    
    int count=0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            count++;
            dfs(adj, visited, i);
 
        }
    }


    return count;
}

    int makeConnected(int n, vector<vector<int>>& connections) {

        int edges=connections.size();
        if(edges<n-1) return -1;

        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            addEdge(adj,connections[i][0],connections[i][1]);
        }
        
        int cc=getComponents(adj);
        return cc-1;

        
    }
};