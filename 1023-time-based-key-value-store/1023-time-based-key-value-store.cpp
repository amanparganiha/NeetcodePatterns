class TimeMap {
private:
    unordered_map<string , vector<pair<int , string>>> keyStr;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyStr[key].emplace_back(timestamp , value);
    }
    
    string get(string key, int timestamp) {
        auto &values = keyStr[key];
        int l = 0 , r = values.size() - 1;
        string res = "";

        while(l <= r){
            int m = l + (r-l) / 2;
            if(values[m].first <= timestamp){
                res = values[m].second;
                l = m + 1;
            }else{
                r = m -1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */