string shiftingLetters(string s, vector<int>& shifts) 
    {
        int n=s.length();
        long int res=s[n-1]-'a';
        
        res+=shifts[n-1];
        
        res%=26;
              s[n-1]='a'+res;
        
        for(int i=n-2;i>=0;i--)
        {
            shifts[i]=(shifts[i]+shifts[i+1])%26;
            
             res=s[i]-'a';
            
            res+=shifts[i];
                       
            res%=26;
            
            s[i]='a'+res;
        }
        
        return s;
    }
