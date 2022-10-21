class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void trav(int node, vector<int> adj[], vector<bool> &isVisited, vector<int> &res){
        if(!isVisited[node]){
            isVisited[node] = true;
            res.push_back(node);
            for(auto val : adj[node]){
                trav(val, adj, isVisited, res);
            }    
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> isVisited(V, false);
        vector<int> res;
        trav(0, adj, isVisited, res);
        return res;
    }
};
