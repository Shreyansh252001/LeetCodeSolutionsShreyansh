class Solution {
public:
   
    int maxPoints(vector<vector<int>>& points) 
    {
        
        int n=points.size(),count=0,m,dup;
        double num,den,slope;
        
        if(n<3)
            return n;
        
        unordered_map<double,int> mp;
        
        for(int i=0;i<(n-count-1);i++)
        {
            m=0;
            dup=0;
            for(int j=i+1;j<n;j++)
            {
                num=(double)(points[j][1]-points[i][1]);
                den=(double)(points[j][0]-points[i][0]);
                
                if(num==0 && den==0)
                {   dup++;m=max(m,dup);continue;}
                else if(den==0)
                    slope=INT_MAX;
                else
                    slope=num/den;
            
                    mp[slope]++;
                
                    m=max(m,mp[slope]);
            }
            
            mp.clear();
            //m=max(m,dup);
            
            count=max(count,m);
        }
        
        return count+1;
    }
};
