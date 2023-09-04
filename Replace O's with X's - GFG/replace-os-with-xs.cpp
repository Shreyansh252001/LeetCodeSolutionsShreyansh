//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> x={1,0,-1,0};
    vector<int> y={0,1,0,-1};
    
    bool isvalid(int i,int j,int n,int m)
    {
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    bool isboundary(int i,int j,int n,int m)
    {
        return i==0||j==0||i==n-1||j==m-1;
    }
    
    void setasnotmarked(int i,int j,int n,int m,vector<vector<char>> &mat)
    {
        mat[i][j]='N';
        
        for(int k=0;k<4;k++)
        {
            if(isvalid(i+x[k],j+y[k],n,m) && mat[i+x[k]][j+y[k]]=='O')
                setasnotmarked(i+x[k],j+y[k],n,m,mat);
        }
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
       /* for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isboundary(i,j,n,m) && mat[i][j]=='O')
                    setasnotmarked(i,j,n,m,mat);
            }
        }*/
        
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]=='O')
                setasnotmarked(i,0,n,m,mat);
            
            if(mat[i][m-1]=='O')
                setasnotmarked(i,m-1,n,m,mat);
        }
        
        
        for(int j=0;j<m;j++)
        {
            if(mat[0][j]=='O')
                setasnotmarked(0,j,n,m,mat);
            
            if(mat[n-1][j]=='O')
                setasnotmarked(n-1,j,n,m,mat);
        }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='O')
                    mat[i][j]='X';
                else if(mat[i][j]=='N')
                    mat[i][j]='O';
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends