class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        sort(costs.begin(),costs.end(),greater<int>());
        
        int count=0,i=costs.size()-1;
        
        while(i>=0 && coins>=costs[i])
        {
            count++;
            coins-=costs[i];
            i--;
        }
        
        return count;
    }
};
