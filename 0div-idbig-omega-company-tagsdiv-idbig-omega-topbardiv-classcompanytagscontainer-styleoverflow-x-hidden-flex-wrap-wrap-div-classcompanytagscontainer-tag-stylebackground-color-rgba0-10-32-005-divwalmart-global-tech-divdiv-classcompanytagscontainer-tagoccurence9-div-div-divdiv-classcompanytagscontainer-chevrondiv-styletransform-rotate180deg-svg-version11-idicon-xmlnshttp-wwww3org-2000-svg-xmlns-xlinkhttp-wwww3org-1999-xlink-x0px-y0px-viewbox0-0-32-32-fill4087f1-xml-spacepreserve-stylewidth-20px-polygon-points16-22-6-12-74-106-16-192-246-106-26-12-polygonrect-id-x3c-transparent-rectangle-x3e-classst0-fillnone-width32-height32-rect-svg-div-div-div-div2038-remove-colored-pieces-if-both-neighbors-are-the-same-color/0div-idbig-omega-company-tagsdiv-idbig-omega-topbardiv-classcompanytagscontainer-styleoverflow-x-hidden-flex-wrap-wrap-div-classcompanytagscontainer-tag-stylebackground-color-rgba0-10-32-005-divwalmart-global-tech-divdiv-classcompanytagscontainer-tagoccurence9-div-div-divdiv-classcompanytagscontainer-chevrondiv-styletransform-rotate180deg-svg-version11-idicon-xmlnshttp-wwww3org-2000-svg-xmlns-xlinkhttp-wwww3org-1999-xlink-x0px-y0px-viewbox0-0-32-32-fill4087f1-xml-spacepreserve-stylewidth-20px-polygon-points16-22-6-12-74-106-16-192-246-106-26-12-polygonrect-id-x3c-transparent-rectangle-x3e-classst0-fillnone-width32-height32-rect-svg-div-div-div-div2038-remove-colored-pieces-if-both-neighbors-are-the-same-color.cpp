class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.length();
        int ca=0,cb=0;
        
        for(int i=1;i<n-1;i++)
        {
            if((colors[i]=='A' && colors[i-1]=='A' && colors[i+1]=='A'))
                ca++;
            else if((colors[i]=='B' && colors[i-1]=='B' && colors[i+1]=='B'))
                cb++;
        }
        
        if(ca==0)
            return false;
        if(cb==0)
            return true;
        
        return (ca-cb)>0;
    }
};