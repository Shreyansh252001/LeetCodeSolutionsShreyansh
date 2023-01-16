class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int n=nums.size();
        
       /* for(int i=0;i<pow(2,n);i++)
        {
            int rem;
            
             while(i!=0)
            {
                rem = n % 2;
                
                // Divide the number by 2.
                n = n / 2;
                 
                //binarynumber = binarynumber+rem * i;

                // To increase the place value.
               //  i=i*10;
            }
            
            
        }*/
        
         
        int res = nums[0];
        
        for (int i = 1; i < nums.size(); i++)
            res = res ^ nums[i];
        return res;
    
    }
};
