class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int currTime = 0;
        int maxTaskTime = INT_MIN;
        int maxTaskWorker = INT_MAX;
        
        for(auto vec: logs){
            int taskTime = vec[1] - currTime;
            
            if(taskTime > maxTaskTime){
                maxTaskTime = taskTime;
                maxTaskWorker = vec[0];
            } else if (taskTime == maxTaskTime){
                maxTaskTime = taskTime;
                maxTaskWorker = min(maxTaskWorker, vec[0]);
            }
            
            currTime = vec[1];
        }
        
        return maxTaskWorker;
    }
};