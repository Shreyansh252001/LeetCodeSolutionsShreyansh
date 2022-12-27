class Solution {
public:
    static bool cmp(pair<long int,int> &a,pair<long int,int> &b)
    {
        return a.first<b.first;
    }
    
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int aR) 
    {
        vector<pair<long int,int>> v;
        int n=rocks.size();
        
        for(int i=0;i<n;i++)
        {
            v.push_back({-rocks[i]+capacity[i],i});
        }
        
        sort(v.begin(),v.end(),cmp);
        
        int i=0,count=0;
        
        while(i<n && v[i].first==0)
        {
            count++;
            i++;
        }
        
        while(aR>0 && i<n)
        {
            if(v[i].first<=aR)
            {
                rocks[v[i].second]+=v[i].first;
            }
            else
                break;
            
                aR-=v[i].first;
    
            if(rocks[v[i].second]==capacity[v[i].second])
            {
                count++;
            }
                i++;
        }
        
        return count;
    }
};
