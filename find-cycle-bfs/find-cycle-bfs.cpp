class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> isVisited(V, false);
        queue<pair<int,int>> que;
        // first will be the element
        // second will be the parent
        for(int i=0; i<V; i++){
            if(!isVisited[i]){
                que.push(make_pair(i, -1));
                isVisited[i] = true;
                while(!que.empty()){
                    pair<int,int> node_val = que.front();
                    que.pop();
                    for(auto val : adj[node_val.first]){
                        if(val != node_val.second){
                            if(isVisited[val]){
                                return true;
                            }
                            isVisited[val] = true;
                            que.push(make_pair(val, node_val.first));
                        }
                    }
                }
            }
        }
        return false;
    }
};
