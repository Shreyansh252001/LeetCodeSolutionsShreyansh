class Solution 
{
    
public:
    
    
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        int m=a.size();
        return a[0]==b[0]?a[m-1]<b[m-1]:a[0]<b[0];
    }
    
    int lower_bound(int m,vector<int> mat)
    {
        int l=0,r=m-1,mid;
        
        while(l<=r)
        {
            mid=(l+r)>>1;
            
            if(mat[mid]==1)
                l=mid+1;
            else
                r=mid-1;
        }
        
        
        return l;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
         int n=mat.size();
        int m=mat[0].size();
        
        
        vector<int> res;
        vector<pair<int,int>> pa;
        
        for(int i = 0;i<n;i++)
        {
            n=mat.size();
            int val = lower_bound(m,mat[i]); 
            
            //lower_bound(mat[i].begin(),mat[i].end(),0,greater<int>())-mat[i].begin();
            pa.push_back({val+1,i});
        }
        
        sort(pa.begin(),pa.end());
        
        for(int i=0;i<k;i++)
        {
            res.push_back(pa[i].second);
        }
        
        return res;
    }
};