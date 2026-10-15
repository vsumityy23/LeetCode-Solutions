class Solution {
public:
    void addedge(vector<vector<int>> & adj,int i,int j){
       
        adj[j].push_back(i);
    }

    bool dfs(  vector<vector<int>>& graph , int i, vector<bool> & visited, vector<bool> & currstack,   vector<int> & ans){

        visited[i]=true;
        currstack[i]=true;
       
        for(int neigh : graph[i]){
            if(!visited[neigh]){
                if(dfs(graph,neigh,visited,currstack,ans)){
                    return true;
                }
            }

            else if(currstack[neigh]){
                return true;
            }
        }
 ans.push_back(i);

        currstack[i]=false;
        return false;


    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {


        vector<vector<int>> graph(numCourses);

        for(int i=0;i<prerequisites.size();i++){
            addedge(graph,prerequisites[i][0],prerequisites[i][1]);
        }


        vector<bool> visited(numCourses,false);
        vector<bool> currstack(numCourses,false);
        vector<int> ans;
        int iscycle=false;

        for(int i=0;i<numCourses;i++){
            

            if(!visited[i]){
                if(dfs(graph,i,visited,currstack,ans)){
                    iscycle=true;
                    break;
                }
            }

        }

       if(iscycle){
        return {};
       }
       reverse(ans.begin(),ans.end());
       return ans;
        
    }
};