class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	/*
	
	De when the result array is in an order similar to which the nodes of the graph itself present.
	say you have u -> v
	in the result array the order should also be u, v (that is, u should preceed v)
	
	*/
	
	void dfs_trav(int V, int root, vector<int> adj[], vector<int> &res, vector<bool> &is_visited){
	    if(!is_visited[root]){
	        is_visited[root] = true;
    	    for(auto i : adj[root]){
    	        dfs_trav(V, i, adj, res, is_visited);
    	    }
	        res.push_back(root);   
	    }
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> res;
	    vector<bool> is_visited(V, false);
	    for(int i=0; i<V; i++){
	        if(!is_visited[i]){
	            dfs_trav(V, i, adj, res, is_visited);
	        }
	    }
	    reverse(res.begin(), res.end());
	    return res;
	}
};
