class DetectSquares {
public:
    map<pair<int,int>,int> mp;
    
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int count = 0;
        int x = point[0];
        int y = point[1];
        for (auto t : mp) {
            pair<int,int> it = t.first;
            
            if (it.first != x && it.second != y && (abs(it.first - x) == abs(it.second-y))) {
                int f1 = mp[{it.first, it.second}];
                int f2 = mp[{it.first, y}];
                int f3 = mp[{x, it.second}];
                count += f1 * f2 * f3;
            }
        }
        return count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */