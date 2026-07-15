class TimeMap {
private:
    unordered_map<string, vector<pair<int,string>>> mp; // key -> list of (timestamp, value)

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string res = "";
        auto& values = mp[key];
        int l = 0;
        int r = values.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (values[mid].first <= timestamp) { // timestamp
                res = values[mid].second; // value
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
