//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfsFinder(int node, vector<int> adj[], vector<int> &res, vector<bool> &isVisited){
        queue<int> que;
        que.push(node);
        while(!que.empty()){
            int currNode = que.front(); que.pop();
            if(isVisited[currNode] == false){
                isVisited[currNode] = true;
                res.push_back(currNode);
                for(auto element: adj[currNode]){
                    que.push(element);
                }
            }
        }
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> isVisited(V, false);
        vector<int> res;
        bfsFinder(0, adj, res, isVisited);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends