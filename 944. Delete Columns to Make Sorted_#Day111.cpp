class Solution {
public:
    int minDeletionSize(vector<string>& strs)
    {
        int n=strs[0].size();
        int count=0;
        string s,x;
        
        for(int i=0;i<n;i++)
        {
            s="";
            
            for(int j=0;j<strs.size();j++)
            {
                s+=strs[j][i];
            }
            x=s;
            sort(s.begin(),s.end());
            
            if(s!=x)
                count++;
        }
        
        return count;
    }
};
