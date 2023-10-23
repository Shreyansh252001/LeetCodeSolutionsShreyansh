class Solution {
public:
    bool isPowerOfFour(int n)
    {
        if(n==0)
            return false;
        
        double g=(double)log(n)/(double)log(4);
        
        return ceil(g)==floor(g);
    }
};