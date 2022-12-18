class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n=temp.size();
      vector<int> s(n);
        stack<int> st;
      
        
        for(int i=0;i<n;i++)
        {
          while(!st.empty() && temp[st.top()]<temp[i])
            s[st.top()]=i-st.top(),st.pop();
          
          st.push(i);
        }
      
        while(!st.empty())
        {  s[st.top()]=0;st.pop();}
      
      return s;
    }
};
