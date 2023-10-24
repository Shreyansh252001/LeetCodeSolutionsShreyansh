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
    vector<int> largestValues(TreeNode* root) 
    {        

        queue<TreeNode*> queue;
        vector<int> ans;
        queue.push(root);
        if (!root) return ans;
        while (!queue.empty()) {
            int level = queue.size();
            int max_val = INT_MIN;
            for (int i = 0; i < level; i++) {
                TreeNode* temp = queue.front();
                queue.pop();
                if (temp->left) {
                    queue.push(temp->left);
                }
                if (temp->right) {
                    queue.push(temp->right);
                }
                max_val = max(max_val, temp->val);
            }
            ans.push_back(max_val);
        }
        return ans;
    

        /*
        if(!root)
            return {};
        
        queue<TreeNode*> q;
        
        int maxi=-1;
        
        q.push(root);
        
        q.push(new TreeNode(-1));
        
        vector<int> v;
        
        while(!q.empty())
        {
            TreeNode* front1=q.front();
            q.pop();
            
            if(front1->val==-1)
            {
                v.push_back(maxi);
                q.push(new TreeNode(-1));
                maxi=-1;
               // cout<<"\n";
            }
            else
            {
                maxi=max(maxi,front1->val);
                // cout<<front1->val<<" ";
                if(front1->left)
                    q.push(front1->left);
                if(front1->right)
                    q.push(front1->right);
            }
        }
        
        return v;*/
    }
};