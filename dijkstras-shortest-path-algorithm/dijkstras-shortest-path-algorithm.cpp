class comparator{
    public:
    bool operator()(const vector<int> &a, const vector<int> &b){
        return a[1] >= b[1];
    }
};

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        // Code here
        vector<int> res(V, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, comparator> pq;
        // queue<vector<int>> pq;
        res[S] = 0;
        for(auto vec : adj[S]){
            res[vec[0]] = vec[1];
            pq.push(vec);
        }
        while(!pq.empty()){
            vector<int> node = pq.top();
            // vector<int> node = pq.front();
            pq.pop();
            for(auto vec:adj[node[0]]){
                if((node[1] + vec[1]) < res[vec[0]]){
                    res[vec[0]] = node[1] + vec[1];
                    pq.push({vec[0], node[1] + vec[1]});
                }
            }
        }
        return res;
    }
};
