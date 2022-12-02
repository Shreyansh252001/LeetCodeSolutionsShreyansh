class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        int a,b;
        
        int lo=matrix[0][0],hi=matrix[n-1][m-1],mid;
        
        while(lo<=hi)
        {
            mid=(lo+hi)>>1;
            
            int count=0,maxnum=lo;
            
            for(int r=0,c=m-1;r<n;r++)
            {
                while(c>=0 && matrix[r][c]>mid)
                    c--;
                
                if(c>=0)
                {
                    count+=(c+1);
                    maxnum=max(maxnum,matrix[r][c]);
                }
            }
            
            if(count==k)
            {
                return maxnum;
            }
            else if(count<k)
                lo=mid+1;
            else
                hi=mid-1;
        }
        
        return lo;
    }
};
