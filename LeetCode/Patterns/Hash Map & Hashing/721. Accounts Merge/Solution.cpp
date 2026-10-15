class Solution {
public:
	int findparent(int u, vector<int>& parent) {
		if (u == parent[u]) {
			return u;
		}
		return parent[u] = findparent(parent[u], parent);
	}
	
	void unionbyrank(int u, int v, vector<int> &parent, vector<int> & rank) {
		int pu = findparent(u,parent);
		int pv = findparent(v,parent);
		
		if (rank[pu]>rank[pv]) {
			parent[pv] = pu;
			
		} else if (rank[pu]<rank[pv]) {
			parent[pu] = pv;
			
		} else {
			parent[pv] = pu;
			rank[pu]++;
			
		}
		
	}
	
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int V=accounts.size();

        unordered_map <string,int> mailmapnode;

        vector<int> rank(V, 0);
		vector<int> parent(V);
		for (int i = 0; i<V; i++) 	parent[i] = i;

        for(int i=0;i<V;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mailmapnode.find(accounts[i][j])==mailmapnode.end()){
                        mailmapnode[accounts[i][j]]=i;
                }else{
                        unionbyrank(mailmapnode[accounts[i][j]],i,parent,rank);
                }
            }
        }

        vector<vector<string>> mails(V);

        for(auto & it:mailmapnode){
            string mail=it.first;
            int node=it.second;

            int parentnode=findparent(node,parent);
            mails[parentnode].push_back(mail);
        }
        
        vector<vector<string>> ans;

        for(int i=0;i<V;i++){
            string name=accounts[i][0];
            if(mails[i].size()!=0){
                vector<string> temp;
                temp.push_back(name);
                sort(mails[i].begin(),mails[i].end());
                for(int j=0;j<mails[i].size();j++){
                    temp.push_back(mails[i][j]);
                }
                ans.push_back(temp);
            }
        }
        return ans;

        
    }
};