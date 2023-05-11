class Solution {
public:
    int minCapability(vector<int>& nums, int k) 
    {
        //talking all the numbers in possibility of 1<=l<=1000000000 as possible 
        long long int l=1,r=1e9,mid,count,n=nums.size();
        
        while(l<r)
        {
            mid=(l+r)>>1;//doing the same step as traditional binary search
            
            count=0;//counting how many such homes can be stealed such that maxium still remains the mid value
            
            for(int i=0;i<n;i++)
            {
                if(mid>=nums[i])
                {
                    count++;//stealing current home then no need of going to next one so incrementing i hence i++ and count++ is because we are taking usrrent home
                    i++;
                }
            }
            
            //if total home stealed are less than minimum required i.e. K then we need to have more homes
            //so increased the limit of selection to above the current mid by doing l=mid+1 to r
            if(count<k)
            {
                l=mid+1;
            }
            else//in opposite if the number of stealed home exceeds k then we are talking the r to current mid so that search range comes down to l to mid;
            {
                r=mid;
            }
        }
        
        return l;
    }
};