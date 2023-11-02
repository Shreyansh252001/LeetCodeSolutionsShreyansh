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
    vector<int> findMode(TreeNode* root) 
    {
        
        /*
        if(!root)
            return {};
        
        stack<TreeNode*> st;
        TreeNode* temp=root;
          st.push(temp);
        map<int,int> mp;
        
        while(!st.empty())
        {
          
            temp=st.top();
            st.pop();
            mp[temp->val]++;
            
            if(root->left)
                st.push(root->left);
            if(root->right)
                st.push(root->right);
            
        }
        
        int maxi=0;
        vector<int> ans;
        
        for(auto it:mp)
        {
            maxi=max(maxi,it.second);
        }
        
        for(auto it:mp)
        {
            if(it.second==maxi)
                ans.push_back(it.first);
        }
        
        return ans;*/
        

        unordered_map<int, int> counter;
        vector<TreeNode*> stack;
        stack.push_back(root);
        
        while (!stack.empty()) {
            TreeNode* node = stack.back();
            stack.pop_back();

            counter[node->val]++;
            if (node->left != nullptr) {
                stack.push_back(node->left);
            }
            if (node->right != nullptr) {
                stack.push_back(node->right);
            }
        }
        
        int maxFreq = 0;

        for (auto& [key, val] : counter) {
            maxFreq = max(maxFreq, val);
        }
        
        vector<int> ans;
        for (auto& [key, val] : counter) {
            if (val == maxFreq) {
                ans.push_back(key);
            } 
        }
        
        return ans;
    
    }
};