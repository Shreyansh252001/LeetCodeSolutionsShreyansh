class Solution {
public:
    
    int minimumRounds(vector<int>& tasks) {
        
        int n=tasks.size();
      //  cout<<n<<"\n";
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[tasks[i]]++;
        }
        
        int round=0;
        
        for(auto it:mp)
        {
           // cout<<it.first<<" "<<it.second<<"\n";
            if(it.second==1)
                return -1;
            
            if(it.second%3==0)
            {
                round+=it.second/3;
                cout<<round<<'\n';
                continue;
            }
            else
                round+=(it.second/3)+1;
        }
        
        return round;
    }
};
