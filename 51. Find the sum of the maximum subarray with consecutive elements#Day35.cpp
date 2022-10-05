class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n+1);
        dp[0]=0;
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            dp[i]=max(nums[i-1],dp[i-1]+nums[i-1]);
            maxi=max(maxi,dp[i]);
        }
        
        return maxi;
    }
};
