class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        int sum=0,n=s.length();
        
        for(int i=0;i<n;i++)
        {
            sum=sum^s[i];
        }
        
        n++;
        
        for(int i=0;i<n;i++)
        {
            sum=sum^t[i];
        }
        
        return sum;
    }
};