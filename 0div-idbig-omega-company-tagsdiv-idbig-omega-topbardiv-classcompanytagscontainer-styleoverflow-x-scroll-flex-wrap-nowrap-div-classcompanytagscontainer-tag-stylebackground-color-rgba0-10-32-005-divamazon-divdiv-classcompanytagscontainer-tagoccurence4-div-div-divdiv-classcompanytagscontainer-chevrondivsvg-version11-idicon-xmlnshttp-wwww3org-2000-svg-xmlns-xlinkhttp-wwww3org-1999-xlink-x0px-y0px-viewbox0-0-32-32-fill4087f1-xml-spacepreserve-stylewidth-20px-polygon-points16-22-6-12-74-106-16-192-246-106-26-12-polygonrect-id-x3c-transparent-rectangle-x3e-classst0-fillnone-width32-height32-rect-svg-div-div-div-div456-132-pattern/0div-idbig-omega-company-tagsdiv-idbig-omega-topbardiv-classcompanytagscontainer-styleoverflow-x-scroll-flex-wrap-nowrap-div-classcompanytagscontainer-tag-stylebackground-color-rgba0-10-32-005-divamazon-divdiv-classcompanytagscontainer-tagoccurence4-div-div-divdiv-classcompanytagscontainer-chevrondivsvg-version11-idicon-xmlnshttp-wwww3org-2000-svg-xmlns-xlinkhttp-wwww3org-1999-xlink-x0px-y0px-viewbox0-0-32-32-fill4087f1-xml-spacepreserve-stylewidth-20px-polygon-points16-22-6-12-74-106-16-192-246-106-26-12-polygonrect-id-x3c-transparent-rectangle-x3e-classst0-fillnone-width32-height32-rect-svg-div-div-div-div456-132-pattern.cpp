class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
       /* int s3 = INT_MIN;
        stack<int> st;
        for( int i = nums.size()-1; i >= 0; i -- ){
            if( nums[i] < s3 ) return true;
            else while( !st.empty() && nums[i] > st.top() ){ 
              s3 = st.top(); st.pop(); 
            }
            st.push(nums[i]);
        }
        */
        
        /*
        O(N^2)
        
        reason for starting from right to left
        
        https://youtu.be/RZXxX1EU364?si=VH9nMjZldu_uSjrm&t=1071
        */
        int n=nums.size();
        
        int numsmid=INT_MIN;
        
        stack<int> st;
        
        st.push(nums[n-1]);
        
        for(int i=n-2;i>=0;i--)
        {
            
            while(!st.empty() && nums[i]>st.top())
            {
                numsmid=st.top();
                
                //taking out all the smaller elements and automatically assigning them to middle element
                
                //and then extitng the while loop
                
                st.pop();
            }
            
            // in the above while loop the middle element automatically gets chosen from the right side of the array , 
            
            // and the below if condition check for the if while loop was not entered then is the current middle element gretaer then it's left element so that if so then return the answer as true. as the greatest element is already found and pused into the stack using st.push(nums[i]) in some of the previoous iterations
            
            
            if(numsmid>nums[i])
            {
                return true;
            }
            
            
            st.push(nums[i]);
        }
        
        return false;
    }
};