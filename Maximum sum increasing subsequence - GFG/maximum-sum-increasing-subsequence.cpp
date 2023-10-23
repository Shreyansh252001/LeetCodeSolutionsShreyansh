//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int tnt(int arr[],int i,int n,int prevval)
	{
	    if(i==n)
	        return prevval;
	        
	   int maxi=0;
	   
	 
	        if(arr[i]>prevval)
	        {
	            maxi=max({maxi,arr[i]+tnt(arr,i+1,n,arr[i]),tnt(arr,i+1,n,prevval)});         
	        }
	        else
	            maxi=max({maxi,tnt(arr,i+1,n,arr[i])});
	    
	    
	    return maxi;
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    //return tnt(arr,0,n,0);
	    
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
    return maxx;
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