class Graph {
public:
    vector<int> cost;
    vector<vector<pair<int,int>>> adj;
    set<int> st;
    int n;
    
    Graph(int n, vector<vector<int>>& edges) 
    {
        /*adj.resize(n);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
        }*/
        
        adj.resize(n);
        for (auto& e: edges)
            adj[e[0]].push_back(make_pair(e[1], e[2]));
    }
    
    void addEdge(vector<int> edge) 
    {
        // adj[edge[0]].push_back(make_pair(edge[1],edge[2]));
        
        adj[edge[0]].push_back(make_pair(edge[1], edge[2]));
    }
    
    int shortestPath(int node1, int node2) 
    {
       /*int n.size();
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        
        cost.resize(n,INT_MAX);
        
        cost[node1]=0;
        
        pq.push({0,node1});*/
        
        
        int n = adj.size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> cost(n, INT_MAX);
        cost[node1] = 0;
        pq.push({0, node1});
        
        while(!pq.empty())
        {
            int currcost=pq.top()[0];
            int currnode=pq.top()[1];
            
            pq.pop();
            
            if(currcost>cost[currnode])
            {
                continue;
            }
            
            if(currnode==node2)
                return currcost;
            
            for(auto neighbour:adj[currnode])
            {
                
                int neigh=neighbour.first;
                int costi=neighbour.second;
                
                int newcost=costi+currcost;
                
                if(newcost<cost[neigh])
                {
                    cost[neigh]=newcost;
                    pq.push({newcost,neigh});
                }
            }
        }
        
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */