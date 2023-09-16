//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    vector<long long int> dp;
    const int mod=1e9+7;
    
    long long ans(int n)
    {
        if(n<0)
            return 0;
            
        if(n==0)
            return 1;
        
        if(dp[n]!=-1)
            return dp[n];
        
        long long int count=0;
        
        for(int i=1;i<=3;i++)
        {
            count+=ans(n-i);
        }
        
        dp[n]=count%mod;
    }
    
    long long countWays(int n)
    {
        dp.resize(n+1,-1);
        
        dp[1]=1;
    
        return ans(n);
       // return dp[n]=ans(n);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends