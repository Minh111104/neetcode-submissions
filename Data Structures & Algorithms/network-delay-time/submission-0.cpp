class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //Step-1: Write Dijkstra's Algo code
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; //minHeap
        
        //Build graph using adjacency list
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto& vec : times){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            //make connections directed graph
            adj[u].push_back({v,w}); //u--->{v,w}
            
        }

        vector<int> result(n+1, INT_MAX); //initialize all distances with infinity
        result[k] = 0; //time of source = 0
        pq.push({0,k}); //push {time, src} in priority queue

        while(!pq.empty()){
            int t = pq.top().first; //time
            int node = pq.top().second; //node
            pq.pop();

            //traverse in neighbors of node
            for(auto& vec : adj[node]){
                int adjNode = vec.first;
                int time = vec.second; 

                //edge relaxation
                if(t + time < result[adjNode]){
                    result[adjNode] = t + time;
                    pq.push({t + time, adjNode});
                }
            }

        }

        int res = INT_MIN;

        for(int i=1; i<=n; i++){

            if(result[i] == INT_MAX) //unreachable node
                return -1;

            res = max(res, result[i]);
        }
        return res;        
    }
};