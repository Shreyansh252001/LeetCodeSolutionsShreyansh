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
        
        
        if(!root)
            return {};
        
vector<TreeNode*> stack;
        stack.push_back(root);
        unordered_map<int,int> mp;
        
           while (!stack.empty()) {
            TreeNode* node = stack.back();
            stack.pop_back();

            mp[node->val]++;
               
            if (node->left != nullptr) {
                stack.push_back(node->left);
            }
            if (node->right != nullptr) {
                stack.push_back(node->right);
            }
        }
        
        
        int maxi=0;
        vector<int> ans;
        
        for(auto it:mp)
        {
            maxi=max(maxi,it.second);
        }
        
     
        for (auto& [key, val] : mp) {
            if (val == maxi) {
                ans.push_back(key);
            } 
        }
        
        return ans;
        
/*
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
        
        return ans;*/
    
    }
};