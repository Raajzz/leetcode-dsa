class Solution {
  public:
    void trav(int V, vector<int> adj[], vector<int> &res, vector<bool> &isVisited){
        queue<int> que;
        int counter = 0;
        while(adj[counter].size() <= 0){
            counter++;
        }
        if(counter == V){
            return;
        }
        que.push(counter);
        while(!que.empty()){
            int node = que.front();
            que.pop();
            res.push_back(node);
            for(auto val : adj[node]){
                if(!isVisited[val]){
                    que.push(val);
                    isVisited[val] = true;
                }
            }
        }
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]){
        vector<int> res;
        vector<bool> isVisited(V, false);
        isVisited[0] = true;
        trav(V, adj, res, isVisited);
        return res;
    }
    
};
