class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size(),l=0,h=n-1,mid,m=grid[0].size(),sum=0;
        
        for(int i=0;i<n;i++)
        {
            int l=0,r=m-1,mid;
            
            while(l<=r)
            {
                mid=(l+r)>>1;
                
                if(grid[i][mid]>=0)
                {
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
            
            sum+=m-l;
            
        }
        
        return sum;
    }
};