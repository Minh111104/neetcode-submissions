class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<int>& v1, vector<int>& v2) {
        vector<vector<int>> res;

        if ((v1[0] <= v2[0] && v2[0] <= v1[1]) || (v2[0] <= v1[1] && v1[1] <= v2[1])) {
            res.push_back({min(v1[0], v2[0]), max(v1[1], v2[1])});
        }
        else {
            res.push_back(v1);
            res.push_back(v2);
        }
        return res;
    }
    
    bool canMergeInterval(vector<int>& v1, vector<int>& v2) {
        return (v1[0] <= v2[0] && v2[0] <= v1[1]) || (v2[0] <= v1[1] && v1[1] <= v2[1]);
    }

    vector<vector<int>> mergeTwoIntervals(vector<int>& v1, vector<int>& v2) {
        vector<vector<int>> res;
        
        res.push_back({min(v1[0], v2[0]), max(v1[1], v2[1])});
        return res;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        vector<int> currentInterval = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (canMergeInterval(currentInterval, intervals[i])) {
                currentInterval = mergeTwoIntervals(currentInterval, intervals[i])[0]; // Extracting the merged interval
            } else {
                ans.push_back(currentInterval);
                currentInterval = intervals[i];
            }
        }
        ans.push_back(currentInterval);
    
    return ans;    
    }
};