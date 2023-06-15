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
    int maxLevelSum(TreeNode* root) 
    {
        int lev=0,sum=0,maxsum=INT_MIN,idx=0,n;
        queue<TreeNode*> q;
        q.push(root);
        
        
        while (!q.empty()) {
            lev++;
            int sumAtCurrentLevel = 0;
            // Iterate over all the nodes in the current level.
            for (int sz = q.size(); sz > 0; --sz) {
                TreeNode* node = q.front();
                q.pop();
                sumAtCurrentLevel += node->val;

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            if (maxsum < sumAtCurrentLevel) {
                maxsum = sumAtCurrentLevel;
                idx = lev;
            }
        }

        /*
        while(!q.empty())
        {
              lev++;
             n=q.size();
            sum=0;
            
            while(n--)
            {
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                
                sum+=q.front()->val;
                q.pop();
            }
            
            if(maxsum<sum)
            {
                maxsum=sum;
                idx=lev;
            }
            
             
        }*/
        
        return idx;
    }
};