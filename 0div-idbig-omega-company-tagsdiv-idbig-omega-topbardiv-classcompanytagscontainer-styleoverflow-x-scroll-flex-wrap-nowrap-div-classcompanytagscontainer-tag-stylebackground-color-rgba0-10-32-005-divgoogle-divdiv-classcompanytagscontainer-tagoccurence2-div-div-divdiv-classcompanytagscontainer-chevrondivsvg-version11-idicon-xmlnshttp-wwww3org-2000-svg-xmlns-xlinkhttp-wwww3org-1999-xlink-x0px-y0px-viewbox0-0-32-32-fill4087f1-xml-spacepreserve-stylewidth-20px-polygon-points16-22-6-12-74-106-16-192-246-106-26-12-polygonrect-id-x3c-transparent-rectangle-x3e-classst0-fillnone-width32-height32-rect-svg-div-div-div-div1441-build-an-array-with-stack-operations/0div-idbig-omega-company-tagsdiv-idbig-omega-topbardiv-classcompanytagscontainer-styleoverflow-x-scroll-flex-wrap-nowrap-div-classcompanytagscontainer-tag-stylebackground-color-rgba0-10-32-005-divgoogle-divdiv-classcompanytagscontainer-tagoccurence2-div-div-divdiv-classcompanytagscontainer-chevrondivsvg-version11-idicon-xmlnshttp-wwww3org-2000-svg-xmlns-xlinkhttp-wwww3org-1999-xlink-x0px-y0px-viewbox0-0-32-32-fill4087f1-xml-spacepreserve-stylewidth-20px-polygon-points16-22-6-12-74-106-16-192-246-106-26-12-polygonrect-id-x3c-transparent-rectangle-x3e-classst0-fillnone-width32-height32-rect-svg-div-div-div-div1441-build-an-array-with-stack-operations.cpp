class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        
        /*
        int i=0,j=1;
        stack<int> st;
        vector<string> v;
        
        while(j<n)
        {
            st.push(j);
             v.push_back("Push");
            
            
                while(!st.empty() && st.top()!=target[i])
                {
                    st.pop();
                    v.push_back("Pop");
                }
           
               
            
            j++;
            i++;
        }
        
        return v;*/
        
   
        vector<string> ans;
        int i = 0;
        
        for (int num : target) {
            while (i < num - 1) {
                ans.push_back("Push");
                ans.push_back("Pop");
                i++;
            }
            
            ans.push_back("Push");
            i++;
        }
        
        return ans;
   
    }
};