class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> indegree(n, 0);
    queue<int> q;
    vector<int> list;

     vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        for(int x : graph[i]){
            adj[x].push_back(i);
            indegree[i]++;
        }
    }


    // Add all nodes with indegree 0 
    // into the queue
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);

    // Kahn’s Algorithm (BFS)
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        list.push_back(top);
        for (int next : adj[top]) {
            indegree[next]--;
            if (indegree[next] == 0)
                q.push(next);
        }
    }
    sort(list.begin(),list.end());
    return list;
    }
};