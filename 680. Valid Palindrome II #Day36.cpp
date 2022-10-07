bool check(int i,int j,string s)
    {
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
                return false;
        }
        
        return true;
    }
    bool validPalindrome(string s) 
    {
        int i=0,j=s.length()-1;
        bool st=false;
        
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                if(!st)
                {   st=true;
                    return (check(i+1,j,s)||check(i,j-1,s));}
                else
                    return false;
            }
        }
        
        return true;
    }
