//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long n) 
    {
        // code here
        //https://www.youtube.com/watch?v=ZzZcFXDcbJw
        if(n<3)
            return n;
        
        long long x=log2(n);
        
        return pow(2,x-1)*x+(n-pow(2,x)+1)+countBits(n-pow(2,x));
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends