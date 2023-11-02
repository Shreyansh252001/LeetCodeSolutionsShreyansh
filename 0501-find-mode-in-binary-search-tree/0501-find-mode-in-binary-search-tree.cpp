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
    void dfs(TreeNode* root,vector<int> &ans)
    {
        if(!root)
            return;
        
        dfs(root->left,ans);
        ans.push_back(root->val);
        dfs(root->right,ans);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans,res;
        //array will contain complete tree in soreted form as it will be an pre order traversal on BST
        dfs(root,ans);
        
        int maxst=0,currst=0,currnum=0;
        
        for(int it:ans)
        {
            if(it==currnum)
                currst++;
            else
            {
                currst=1;
                currnum=it;
            }
            
            if(currst>maxst)
            {
                maxst=currst;
                res={};
                
            }
            
            
            if(currst==maxst)
            {
                res.push_back(it);
            }
        }
        
        return res;
    }
};