class Solution {
public:
    string decodeAtIndex(string S, int K)
    {
        
       /* int n=s.length(),i,size=n;
        
        for(i=0;n<k;i++)
        {
            n+=isdigit(s[i])?n*(s[i]-'0'):n+1;
        }
        
        swap(size,n);
        
        for(int i=n-1;i>=0;i--)
        {
            size=size%k;
            
            if(isalpha(s[i]) && k==0)//s[i] is a character with k=0
            {
                cout<<"enterd"<<"\n";
               return ""+s[i];
                
            }
            else if(isalpha(s[i]))
            {
                size--;
            }
            else
                size=size/(s[i]-'0');
        }
        
        return "";*/
        
        long N = 0, i;
        for (i = 0; N < K; ++i)
            N = isdigit(S[i]) ? N * (S[i] - '0') : N + 1;
        while (i--)
            if (isdigit(S[i]))
                N /= S[i] - '0', K %= N;
            else if (K % N-- == 0)
                return string(1, S[i]);
        return "lee215";
    }
};