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
class Solution 
{
public:
    
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
public:
    TreeNode* temp;
    int mindistance=INT_MAX;
    // the whole process is just same as representing the tree in form of sorted array
    // it is just that the right most member is remembered from among the child nodes as that node will be the one which will come before the root node from which the call to just below node is made
    //so suppose tree is 
    /*
                236
            /         \
        104            701
        /   \          /   \
    NULL2nd  227   NULL1st  911
    
    then if we see the following tree in sorted array form the topmost node will come at centre
    
    NULL2nd 104 227 236 NULL1st 701 911
    
    so on calling the left child our first and formost task is to remember the largest among left so find the smallest difference with corresponding root node
    
    and as soon as the difference is calculated the temp node must be updated to the root value and called on for the right with the checking for the child on the left (see the array the top root's right child's left most element is first seen nearest to the main top root find difference between topmost root and topmosts right child's leftmost part)
    
    also keep on updating simultaneousy the minimum difference using inbuilt min function.
    */
    
    vector<int> ans;
    
//     void inorder(TreeNode* root)
//     {
//         if(!root)
//             return;
        
//         inorder(root->left);
        
//         if(temp!=NULL)
//         {
//             mindistance=min(mindistance,abs(temp->val-root->val));
//         }
        
//         temp=root;
        
//         inorder(root->right);
//     }
    
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
         
        inorder(root->left);
        
        ans.push_back(root->val);
        
        inorder(root->right);
    }
  
    int getMinimumDifference(TreeNode* root) 
    {
        inorder(root);
        
        //sort(ans.begin(),ans.end());
        int mindifference=INT_MAX;
        
        for(int i=1;i<ans.size();i++)
        {
            mindifference=min(mindifference,ans[i]-ans[i-1]);
        }
        
        return mindifference;
    }
};