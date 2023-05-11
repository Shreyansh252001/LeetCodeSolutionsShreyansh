class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(vector<int> nums1,vector<int> nums2,int n1,int n2)
    {
        if(n1<0||n2<0)
            return 0;
        
        if(nums1[n1]==nums2[n2])
            return 1+solve(nums1,nums2,n1-1,n2-1);
        
        if(dp[n1][n2]!=-1)
            return dp[n1][n2];
    
        return dp[n1][n2]=max(solve(nums1,nums2,n1-1,n2),solve(nums1,nums2,n1,n2-1));
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
         int n=nums1.size(),m=nums2.size();
        
        dp.resize(n,vector<int>(m,-1));
        
        return dp[n-1][m-1]=solve(nums1,nums2,n-1,m-1);
    }
};