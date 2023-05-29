//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        // code here
       int m=Pattern.length(),i,count=0,d;
       
       for(auto it:Pattern)
        if(it>='A' && it<='Z')
            count++;
            
       vector<string> str={"-1"};
       
            for(auto it:Dictionary)
            {
                i=0;
                d=0;
                
                for(int j=0;j<it.length() && i<m ;j++)
                {
                    if(it[j]>='A' && it[j]<='Z')
                    {
                            d++;
                        if(Pattern[i]==it[j])
                        {
                            i++;
                        }
                    }
                }
                
                if(i==m && count==d)
                    str.push_back(it);
            }
        
        if(str.size()!=1)
            str.erase(str.begin());
        
        return str;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends