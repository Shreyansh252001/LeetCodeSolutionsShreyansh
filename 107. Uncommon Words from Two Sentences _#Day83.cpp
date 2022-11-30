
/*little slow solution*/
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        
      map<string,int> mp;
      vector<string> v;
      
      int i=0,j=0,n=s1.length(),m=s2.length();
      string s="";
      
      for(int i=0;i<n;i++)
      {
        if(s1[i]!=' ')
          s=s+s1[i];
        else
        {
            mp[s]++;
          s="";
        }
      }
      mp[s]++;
      s="";
      
      for(int j=0;j<m;j++)
      {
        if(s2[j]!=' ')
            s=s+s2[j];
        else
        {
          mp[s]++;
          s="";
        }
      }
      mp[s]++;
      for(auto it:mp)
      {
        if(it.second==1)
        {
          v.push_back(it.first);
        }
      }
      
      return v;
    }
};


/*fast solution using string stream*/
  unordered_map<string,int> s1_map;
        
        istringstream iss1(s1);
        string s;
        while (iss1 >> s) {
            s1_map[s]++; // count freq
        }

        istringstream iss2(s2);
        while (iss2 >> s) {
            s1_map[s]++; // count freq
        }
        
        vector<string> ans;
        for( unordered_map<string,int>::iterator ite = s1_map.begin();
           ite != s1_map.end();
           ite++)
        {
            if(ite->second == 1)
            {
                ans.push_back(ite->first);
            }
        }
        return ans;
