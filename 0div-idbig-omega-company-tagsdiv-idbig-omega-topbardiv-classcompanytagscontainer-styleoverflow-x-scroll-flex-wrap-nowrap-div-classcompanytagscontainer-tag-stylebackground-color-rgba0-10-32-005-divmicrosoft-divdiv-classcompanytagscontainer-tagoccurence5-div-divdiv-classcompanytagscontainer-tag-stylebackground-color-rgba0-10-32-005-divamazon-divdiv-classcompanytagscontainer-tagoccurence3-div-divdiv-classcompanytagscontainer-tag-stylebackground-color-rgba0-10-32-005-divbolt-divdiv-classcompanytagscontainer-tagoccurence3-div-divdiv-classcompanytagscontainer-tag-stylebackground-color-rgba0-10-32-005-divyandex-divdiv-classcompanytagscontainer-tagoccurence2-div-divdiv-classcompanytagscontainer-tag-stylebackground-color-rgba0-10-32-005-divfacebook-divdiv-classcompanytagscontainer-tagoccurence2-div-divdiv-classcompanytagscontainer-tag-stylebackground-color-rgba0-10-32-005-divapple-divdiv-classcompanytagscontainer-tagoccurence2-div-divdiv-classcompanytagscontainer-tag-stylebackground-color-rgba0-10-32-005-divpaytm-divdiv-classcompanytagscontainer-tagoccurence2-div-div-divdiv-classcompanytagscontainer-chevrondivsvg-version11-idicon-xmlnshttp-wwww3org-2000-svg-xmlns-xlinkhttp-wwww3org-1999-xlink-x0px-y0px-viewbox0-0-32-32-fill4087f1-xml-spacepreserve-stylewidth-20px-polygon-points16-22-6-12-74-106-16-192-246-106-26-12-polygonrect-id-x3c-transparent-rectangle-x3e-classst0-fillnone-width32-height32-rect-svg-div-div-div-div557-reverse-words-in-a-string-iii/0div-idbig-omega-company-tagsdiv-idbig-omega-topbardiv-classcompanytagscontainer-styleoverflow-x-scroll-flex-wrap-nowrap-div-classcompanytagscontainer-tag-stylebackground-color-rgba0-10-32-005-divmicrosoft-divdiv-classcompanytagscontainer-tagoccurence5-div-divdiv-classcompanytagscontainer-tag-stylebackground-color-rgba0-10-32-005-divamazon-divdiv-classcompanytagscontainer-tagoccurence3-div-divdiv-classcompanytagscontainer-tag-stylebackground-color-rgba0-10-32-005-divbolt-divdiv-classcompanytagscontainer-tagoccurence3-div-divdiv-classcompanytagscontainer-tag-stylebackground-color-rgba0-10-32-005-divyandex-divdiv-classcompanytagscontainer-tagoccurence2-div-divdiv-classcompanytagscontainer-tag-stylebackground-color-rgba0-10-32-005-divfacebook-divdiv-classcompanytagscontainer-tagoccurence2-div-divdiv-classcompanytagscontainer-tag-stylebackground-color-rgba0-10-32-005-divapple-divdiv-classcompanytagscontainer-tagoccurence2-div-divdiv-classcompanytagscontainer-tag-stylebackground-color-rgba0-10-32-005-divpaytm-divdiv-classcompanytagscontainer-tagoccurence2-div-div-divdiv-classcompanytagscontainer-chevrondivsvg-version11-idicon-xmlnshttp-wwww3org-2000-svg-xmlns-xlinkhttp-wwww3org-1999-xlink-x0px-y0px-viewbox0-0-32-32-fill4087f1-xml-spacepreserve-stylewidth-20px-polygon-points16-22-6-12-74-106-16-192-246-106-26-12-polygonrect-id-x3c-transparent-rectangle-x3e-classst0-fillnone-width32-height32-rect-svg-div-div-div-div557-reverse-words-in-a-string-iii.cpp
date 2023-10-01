class Solution {
public:
    string reverseWords(string s) 
    {
        stack<char> st;
        
        string s1="";
        
        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                while(!st.empty())
                {
                    s1+=st.top();
                    st.pop();
                }
                
                s1+=s[i];
            }
            else
            {
                st.push(s[i]);
            }
        }
        
                while(!st.empty())
                {
                    s1+=st.top();
                    st.pop();
                }
        
        return s1;
    }
};