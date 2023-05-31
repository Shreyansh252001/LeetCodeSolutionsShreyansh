class UndergroundSystem {
public:
    unordered_map<long int,pair<string,long int>> start;
    unordered_map<string,pair<int,int>> mp;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        start[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        string s=start[id].first+"-"+stationName;
        
        mp[s].first+=t-start[id].second;
        mp[s].second++;
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        string s=startStation+"-"+endStation;
        
        return (double)mp[s].first/(double)mp[s].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */