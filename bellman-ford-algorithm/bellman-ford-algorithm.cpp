
class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> res(V, 100000000);
        res[S] = 0;
        for(int i=0; i<V-1; i++){
            for(auto vec : adj){
                // vec structure -> [source | destination | weight ]
                if(res[vec[0]] != 100000000){
                    if(res[vec[0]] + vec[2] < res[vec[1]]){
                        res[vec[1]] = res[vec[0]] + vec[2];
                    }
                }
            }
        }
        return res;
    }
};
