class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int V, int src) {

        vector<vector<pair<int,int>>> adj(V);
        
         for(auto & edge : times ){

            int u=edge[0]-1;
            int v=edge[1]-1;
            int w=edge[2];
            adj[u].push_back({v,w});
        }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);

    // Distance from source to itself is 0
    dist[src-1] = 0;
    pq.emplace(0, src-1);

    // Process the queue until all reachable vertices are finalized
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int d = top.first;  
        int u = top.second; 

        // If this distance not the latest shortest one, skip it
        if (d > dist[u])
            continue;

        // Explore all neighbors of the current vertex
        for (auto &p : adj[u]) {
            int v = p.first; 
            int w = p.second; 

           
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;   
                pq.emplace(dist[v], v);
            }
        }
    }


int ans=-1;

    for(int d :dist){
        ans=max(ans,d);
        if(d==INT_MAX) return -1;
        
    }
return ans;


    }
};