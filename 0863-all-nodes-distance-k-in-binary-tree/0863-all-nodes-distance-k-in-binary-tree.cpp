/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    map<TreeNode*,TreeNode*> mp;
    
    void preord(TreeNode* root)
    {
        if(!root)
            return;
        
        if(root->left)
        {
            preord(root->left);
            mp[root->left]=root;
        }
        
        if(root->right)
        {
            preord(root->right);
            mp[root->right]=root;
        }
        
        return;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)  
    {
        int m;
        
       // mp[root]=NULL;
        
        preord(root);
        
        vector<int> v;
        
        queue<TreeNode*> q;
        
        q.push(target);
        
        set<TreeNode*> vis;
        
        TreeNode* temp;
        
        while(!q.empty() && (k--))
        {
            m=q.size();
            
            while(m--)
            {
                temp=q.front();
                
                q.pop();
                
                vis.insert(temp);
                
                    if(mp.find(temp)!=mp.end() && !vis.count(mp[temp]))
                        q.push(mp[temp]);
                
                    if(!vis.count(temp->left) && temp->left)
                        q.push(temp->left);
                
                    if(!vis.count(temp->right) && temp->right)
                        q.push(temp->right);
            }
        }
        
        while(!q.empty())
        {
            TreeNode* t=q.front();
            
            if(t)
                v.push_back(t->val);
            
            q.pop();
        }
            
        return v;
    }
};