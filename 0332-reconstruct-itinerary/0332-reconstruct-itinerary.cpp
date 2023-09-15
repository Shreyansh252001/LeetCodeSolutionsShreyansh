class Solution {
public:
    
    /*
            unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;

        for (const auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        vector<string> newItinerary;
        stack<string> st;
        st.push("JFK");

        while (!st.empty()) {
            string currentAirport = st.top();

            if (graph.find(currentAirport) != graph.end() && !graph[currentAirport].empty()) {
                st.push(graph[currentAirport].top());
                graph[currentAirport].pop();
            } else {
                newItinerary.push_back(st.top());
                st.pop();
            }
        }

        reverse(newItinerary.begin(), newItinerary.end());
        return newItinerary;   
        */
    /*
     vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> adj;
        vector<string> ans;
        int n=tickets.size();
        //Make graph
        for(int i=0;i<n;++i)
            adj[tickets[i][0]].insert(tickets[i][1]);
        
        stack<string> mystack;
        mystack.push("JFK");    //JFK is our fixed starting point
        while(!mystack.empty())
        {
            string src = mystack.top();
            if(adj[src].size()==0)  //No further travel possible
            {
                ans.push_back(src);
                mystack.pop();
            }
            else
            {
                auto dst = adj[src].begin();
                mystack.push(*dst);
                adj[src].erase(dst);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }*/
    
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        map<string,multiset<string>> mp;
        
        for(auto it:tickets)
        {
            mp[it[0]].insert(it[1]);
        }
        
        stack<string> st;
        
        st.push("JFK");
        
        string s;
        
        vector<string> ans;
        
        while(!st.empty())
        {
            s=st.top();
            
            if(mp[s].size()==0)
            {
                 ans.push_back(s);
                st.pop();
            }
            else
            {
               /* string d=*mp[s].begin();
                st.push(d);
                mp[s].erase(d);*/
                
                auto dst = mp[s].begin();
                st.push(*dst);
                mp[s].erase(dst);
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};