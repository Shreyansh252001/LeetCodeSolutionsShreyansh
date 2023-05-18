//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    
    int n,m;
    
    void help(vector<vector<int>> & arr, int i, int j){
        if(i<0|| j<0|| i==n || j==m || arr[i][j]==0) 
            return ;
        arr[i][j]=0;
        
        help(arr, i+1, j);
        help(arr, i-1, j);
        help(arr, i, j+1);
        help(arr, i, j-1);
        
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        
        n=N;
        m=M;
        
        int ans = 0;
        // for(int i=0; i<N; i++)
        // {
        //     for(int j=0; j<M; j++)
        //     {
        //         if(matrix[i][j]==1)
        //         {
        //             if(i==0 || i==N-1 || j==0 || j==M-1)
        //             {
        //                 help(matrix, i, j, N, M);
        //             }
        //         }
        //     }
        // }
        
        for(int i=0;i<n;i++)
        {
            help(matrix,i,0);
            
            help(matrix,i,m-1);
        }
        
        for(int j=0;j<m;j++)
        {
             help(matrix,0,j);
            
            help(matrix,n-1,j);
        }
        
        for(int i=1; i<n-1; i++)
        {
            for(int j=1; j<m-1; j++)
            {
                if(matrix[i][j]==1)
                {
                    ans++;
                    help(matrix, i, j);
                }
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends