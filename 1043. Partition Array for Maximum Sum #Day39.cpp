/*Recursive not working but just to give an idead of recursive tree*/
 int func(int i,vector<int> &arr,int k,int n)
    {
        if(i>=n)
            return 0;
        
        int res,maxi=0;        
        
        for(int j=0;j<k && i+j<n;j++)
        {
            res=*max_element(arr.begin()+i,arr.begin()+i+j+1);
            
            maxi=max(maxi,res*(j+1)+func(i+j+1,arr,k,n));
        }
        
        return maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k)
    {
        int n=arr.size();
        
        return func(0,arr,k,n);
        return 0;
    }
/*DP*/
int f(int i,vector<int>& arr,int k,int n,vector<int>& dp){
		if(i>=n) return 0;
		if(dp[i]!=-1) return dp[i];
		int ans=0;
		for(int j=0;j<k && i+j<n;j++){
			int maxi=*max_element(arr.begin()+i,arr.begin()+i+j+1);
			int op=(j+1)*maxi+f(i+j+1,arr,k,n,dp);
			ans=max(ans,op);
		}
		return dp[i]=ans;
	}

	int maxSumAfterPartitioning(vector<int>& arr, int k) {
		int n=arr.size();
		vector<int> dp(n,-1);
		return f(0,arr,k,n,dp);
	}
