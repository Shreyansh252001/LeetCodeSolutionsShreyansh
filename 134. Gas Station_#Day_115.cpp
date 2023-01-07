class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
    int totalGas = 0;
    int totalCost = 0;
    int totalRemaining = 0;
    for(int i=0;i<gas.size();i++){
        totalGas += gas[i];
        totalCost += cost[i];
        totalRemaining += gas[i] - cost[i];
        if(totalRemaining<0){
            start = i+1;
            totalRemaining = 0;
        }
    }
    if(totalGas>=totalCost) return start;
    return -1; 
    }
};
