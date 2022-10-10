  bool canPartition(vector<int>& arr) {
    int sum=0;
    for(auto x:arr)sum=sum+x;
    if(sum%2!=0) return false;
    int k=sum/2;
    int n=arr.size();
    vector<vector<bool>>dp(n,vector<bool>(k+1));
    for(int i=0;i<n;i++)dp[i][0]=1;
    if(arr[0]<=k)
        dp[0][arr[0]] = true;
    for(int index=1;index<n;index++){
        for(int sum=0;sum<=k;sum++){
            bool pick=false;
            if(sum>=arr[index])
            pick=dp[index-1][sum-arr[index]];
            bool notpick=dp[index-1][sum];   
            dp[index][sum]=pick|notpick; 
        }
    }
    return dp[n-1][k];
    }
