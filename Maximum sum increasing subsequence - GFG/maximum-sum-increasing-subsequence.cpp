//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:

	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    //return tnt(arr,0,n,0);
	    
	    vector<int> dp(n);
	    
	    int ans=0;
	    
	    dp[0]=arr[0];
	    
	    for(int i=1;i<n;i++)
	    {
            int maxx=0;
            dp[i]=arr[i];
            
            for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j] && dp[j]>maxx)// the current i should be greater than
                //all previous j's and dp[j] means all addition tiil jth index which is stored in dp[j]
                //we have to select the maximum addition of all the previous j provided that current arr[j]<arr[i]
                {
                    maxx=dp[j];
                }
            }
            
            dp[i]+=maxx;
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        if(dp[i]>ans)
	        {
	            ans=dp[i];
	        }
	    }
	    
	    return ans;
	    
	    
	/*    
	int ans[n];
	       
    ans[0]=arr[0];
    
    for(int i=1;i<n;i++)
    {
        int maxx=0;
        
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i] and ans[j]>maxx)
                 maxx=ans[j];
        }
        
        ans[i]=arr[i]+maxx;
    }
    
    int maxx=ans[0];
    
    
    for(int i=0;i<n;i++)
    {
        if(ans[i]>maxx)
        {
            maxx=ans[i];
        }
    }
    return maxx;*/
    
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends