#define max_element 40
class Solution {
public:
    
  /*  int map_str(string s,string c,int num)
    {
        int ii;
        
        for(ii=0;ii<num;ii++)
        {
            if(!s.compare(c))
                
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)     {
        vector<vector<int>> v(N,vector<int>(n,-1));
        
        int num_str=0;
        
        vector<int> char(max_elements);
        
        int rt[max_elements];
        
        for(int i=0;i<max_elements;i++)
            rt[i]=i;
        
        string c;
        
        int map_id1,map_id2;
        
        vector<vector<double>> wt(max_elements,vector<double>(max_elements,1.000000));
        
        int rnk[max_elements]={1};
        
        for(int ii=0;ii<equations.size();ii++)
        {
            c=equations[ii][0];
            
            if(!(map_id1=map_str(str,c,num_str)))
            {
                strs[num_strs]=s;
                map_id1=num_str;
                num_str++;
            }
            else
                map_id1--;
            
            c=equations[ii][1];
            
            if(!(map_id2=map_str(str,c,num_str)))
            {
                strs[num_strs]=s;
                map_id2=num_str;
                num_str++;
            }
            else
                map_id2--;
        }
    }*/
    
    bool dfs(string src,string dest,unordered_map<string,bool> &vis,unordered_map<string,vector<pair<string,double>>> &mp,double temp,double &val)
    {
        vis[src]=true;
        
        if(src==dest)
        {
            val=temp;
            return true;
        }
        
        string neigh;
        
        double ratio;
        
        for(int i=0;i<mp[src].size();i++)
        {
            neigh=mp[src][i].first;
            ratio=mp[src][i].second;
            
            if(!vis[neigh])
            {
                if(dfs(neigh,dest,vis,mp,temp*ratio,val))
                    return true;
            }
        }
        
        return false;
    }
    
    
    
    
    
    
    
    
    
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
        {
            int n=values.size();
        
            unordered_map<string,vector<pair<string,double>>> mp;
        
            //making the the adjacency list with pairs of {other_vertice, value} pushed inside each of the vertices of pair
            
            for(int i=0;i<n;i++)
            {
                mp[equations[i][0]].push_back({equations[i][1],values[i]});
                mp[equations[i][1]].push_back({equations[i][0],(double)1/values[i]});
                
            }
        
        
            int q=queries.size();
        
            vector<double> res;
        
            for(int i=0;i<q;i++)
            {
                unordered_map<string,bool> vis;
                
                double val=-1.0,temp=1.0;
                
                if(mp.find(queries[i][0])!=mp.end())
                {
                    dfs(queries[i][0],queries[i][1],vis,mp,temp,val);
                }
                
                res.push_back(val);
            }
        
            return res;
        }
};