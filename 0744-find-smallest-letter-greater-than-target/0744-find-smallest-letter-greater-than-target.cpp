class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int n=letters.size(),l=0,h=n-1,mid;
        
        while(l<=h)
        {
            mid=(l+h)>>1;
            
            if(letters[mid]<=target)
                l=mid+1;
            else
                h=mid-1;
        }
        
        return l==n?letters[0]:letters[l];
    }
};