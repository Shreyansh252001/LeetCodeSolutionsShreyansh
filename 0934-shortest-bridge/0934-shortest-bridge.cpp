class Solution 
{
    
public:
    int n,m;
    int paint(vector<vector<int>>&grid,int i,int j)
    {
        if(min(i,j)<0 || max(i,j)>=grid.size() || grid[i][j]!=1)
                return 0;
        
        grid[i][j]=2;
        
        return 1+paint(grid,i+1,j)+paint(grid,i-1,j)+paint(grid,i,j-1)+paint(grid,i,j+1);
    }
    bool expand(int i,int j,vector<vector<int>> &grid,int cl)
    {
        if(min(i,j)<0 || max(i,j)==grid.size())
            return false;
        
        grid[i][j] = (grid[i][j]==0)?cl+1:grid[i][j];
        
        return grid[i][j]==1;
    }
    
    int shortestBridge(vector<vector<int>> &grid)
    {
        n=grid.size();
        m=grid[0].size();
        
        for(int i=0,found=0;!found && i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size() && !found;j++)
            {
                found=paint(grid,i,j);
            }
        }
        
        for(int cl=2; ;++cl)
        {
            for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid.size();j++)
                {
                    if(grid[i][j]==cl && (expand(i+1,j,grid,cl) || expand(i,j+1,grid,cl) || expand(i-1,j,grid,cl) || expand(i,j-1,grid,cl)))
                        return cl-2;
                }
            }
        }
    }
    
    
   /* 
    queue<vector<int>> q;
    
    vector<int> x={1,0,-1,0};
    vector<int> y={0,1,0,-1};
    
    bool check(int i,int j)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    
    int smallest(vector<vector<int>> &grid,int i,int j)
    {
        int val=INT_MAX;
        
        // if(grid[i][j]==1)
        //     return 0;
        
        int i1,j1,st=false;
        
        for(int k=0;k<4 && !st;k++)
        {
            i1=i+x[k];
            j1=j+y[k];
            
            if(check(i1,j1))
                if(grid[i1][j1]==1)
                {
                    grid[i1][j1]=2;
                    q.push({i1,j1});
                    val=min(val,1+smallest(grid,i1,j1));
                }
                // else if(grid[i1][j1]==1)
                //     st=true;
        }
        
        return (val==INT_MAX || st)?0:val;
    }
    
    int shortestBridge(vector<vector<int>>& grid) 
    {
        int val=INT_MAX;
        
        n=grid.size();
        m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    val=min(val,smallest(grid,i,j));
            }
        }
        
        int distance=0;
        
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            
            
        }
        return val;
    }*/
    
};