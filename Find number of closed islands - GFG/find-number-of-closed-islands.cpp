//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void help(vector<vector<int>> & arr, int i, int j, int& N, int& M){
        if(i<0|| j<0|| i==N|| j==M || arr[i][j]==0) 
            return ;
        arr[i][j]=0;
        
        help(arr, i+1, j, N, M);
        help(arr, i-1, j, N, M);
        help(arr, i, j+1, N, M);
        help(arr, i, j-1, N, M);
        
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        int ans = 0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(matrix[i][j]==1)
                {
                    if(i==0 || i==N-1 || j==0 || j==M-1)
                    {
                        help(matrix, i, j, N, M);
                    }
                }
            }
        }
        
        
        for(int i=1; i<N-1; i++)
        {
            for(int j=1; j<M-1; j++)
            {
                if(matrix[i][j]==1)
                {
                    ans++;
                    help(matrix, i, j,N ,M);
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