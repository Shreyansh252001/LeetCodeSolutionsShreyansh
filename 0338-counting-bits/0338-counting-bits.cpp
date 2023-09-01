class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> ans;
        
        for(int i=0;i<=n;i++)
        {
            int count=0;
            int g=i;
            
            while(g)
            {
             
                if(g&1)
                    count++;
                   g=(g>>1);
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};