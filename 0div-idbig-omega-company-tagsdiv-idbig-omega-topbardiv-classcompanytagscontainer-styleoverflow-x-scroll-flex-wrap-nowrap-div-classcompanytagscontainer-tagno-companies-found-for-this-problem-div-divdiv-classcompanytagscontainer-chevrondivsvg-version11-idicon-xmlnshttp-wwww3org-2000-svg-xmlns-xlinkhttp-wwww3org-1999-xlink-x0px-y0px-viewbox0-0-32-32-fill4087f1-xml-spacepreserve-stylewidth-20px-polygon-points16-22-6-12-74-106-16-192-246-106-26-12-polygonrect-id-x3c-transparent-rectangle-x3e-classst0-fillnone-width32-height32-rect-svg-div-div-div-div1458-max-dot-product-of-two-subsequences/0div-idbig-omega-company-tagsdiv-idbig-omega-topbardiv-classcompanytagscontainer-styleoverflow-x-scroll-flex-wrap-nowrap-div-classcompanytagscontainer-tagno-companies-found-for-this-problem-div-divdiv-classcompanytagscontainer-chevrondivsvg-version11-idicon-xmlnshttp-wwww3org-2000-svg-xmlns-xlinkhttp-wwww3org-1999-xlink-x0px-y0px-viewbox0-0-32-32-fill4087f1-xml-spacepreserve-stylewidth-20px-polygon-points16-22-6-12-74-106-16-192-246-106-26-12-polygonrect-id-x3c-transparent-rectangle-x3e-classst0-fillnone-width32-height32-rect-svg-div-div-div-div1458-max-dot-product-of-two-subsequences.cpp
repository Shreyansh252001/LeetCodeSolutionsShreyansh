class Solution {
public:
    vector<vector<long long int>> dp;
    int n,m;
            const int INF = 10e7;
    
    long long int maxpro(vector<int> nums1,vector<int> nums2,int i,int j)
    {
        if(i==n || j==m)
            return 0;
        
        if(dp[i][j]!=INT_MIN)
            return dp[i][j];
        
        long long int donotselect=maxpro(nums1,nums2,i+1,j+1);
        
        long long int selectboth=nums1[i]*nums2[j]+donotselect;
        
        long long int selectone = max(maxpro(nums1,nums2,i+1,j),maxpro(nums1,nums2,i,j+1));
        
        return dp[i][j]=max({selectone,selectboth});
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        n=nums1.size();
        m=nums2.size();
        
        long long int firstMax = INT_MIN;
        long long int secondMax = INT_MIN;
        
        long long int firstMin = INT_MAX;
        long long int secondMin = INT_MAX;
        
        for (long long int num: nums1)
        {
            firstMax = max(firstMax, num);
            firstMin = min(firstMin, num);
        }
        
        for (long long int num: nums2)
        {
            secondMax = max(secondMax, num);
            secondMin = min(secondMin, num);
        }
        
        // these both loops are for cases in which there is one array of all positives and another array of all negatives
        
        //checking by multiplying if the number greater than 0 is maximum of all positive and number <0 is maximum of all negative numbers
        
        if (firstMax < 0 && secondMin > 0) //first array all negative so take first maximum and second array all positive so so to reduce the negative value of final result minimum of second array
        {
            return firstMax * secondMin;
        }
        
        if (firstMin > 0 && secondMax < 0) //first array all positive so take first minimum and second array all negative so maximum of second array
        {
            return firstMin * secondMax;
        }

        dp.resize(n+1,vector<long long int>(m+1,INT_MIN));
        
        dp[0][0]=nums1[0]*nums2[0];
        
       // return maxpro(nums1,nums2,0,0);
       /* for(int i=1;i<n;i++)
            dp[i][0]=max(dp[i-1][0],(long long)(nums2[0]*nums1[i]));
        
        for(int j=1;j<m;j++)
            dp[0][j]=max(dp[0][j-1],(long long)(nums2[j]*nums1[0]));*/
        
        
     /*   for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=max({(long long)(nums1[i-1]*nums2[j-1]),dp[i-1][j-1]+(long long)(nums1[i-1]*nums2[j-1]),dp[i-1][j],dp[i][j-1]});
            }
        }
        
        return dp[n][m];*/

         
        vector<vector<int>> dp(n, vector<int>(m));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                
                dp[i][j] = nums1[i] * nums2[j];
                if (i && j) dp[i][j] += max(dp[i - 1][j - 1], 0);
                if (i) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (j) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};