class Solution {
public:
    string decodeAtIndex(string s, int K) 
    {
        
        long int size=0,n=s.length();
        
        for(int i=0;i<n;i++)
        {
            size=isalpha(s[i])?size+1:(s[i]-'0')*(size);
        }
        
        int i=n-1;
        
       //cout<<sum<<"\n";
        
          for(int i = n-1; i>=0; i--) 
          {
            K = K%size;
            
            if(K == 0  && isalpha(s[i]))
                return string(1, s[i]);
            
            if(isalpha(s[i]))
                size--;
            else
                size = size/(s[i]-'0');
        }
        return "game over";
    }
};