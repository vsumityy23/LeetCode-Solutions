/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* treebanaobc(vector<int> preorder,int prei,int prej,int ini,int inj,unordered_map <int,int> & hash){
        
        if(prei>prej || ini>inj) return nullptr;

        TreeNode * root =  new TreeNode(preorder[prei]);
        
        int leftlen=hash[preorder[prei]]- ini;


        root->left=treebanaobc(preorder,prei+1,prei+(inj-ini), ini,hash[preorder[prei]]-1,hash);
        root->right=treebanaobc(preorder,prei+1+leftlen,prej, ini+leftlen+1,inj,hash);

        return root;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map <int,int> hash;

        for(int i=0;i<inorder.size();i++){
            hash[inorder[i]]=i;
        }

        return treebanaobc(preorder,0,preorder.size()-1,0,inorder.size()-1,hash); 
      
        
    }
};