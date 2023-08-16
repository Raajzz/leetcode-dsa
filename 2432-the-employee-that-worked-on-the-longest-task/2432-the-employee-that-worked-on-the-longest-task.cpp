class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        unordered_map<int,int> mp;
        int currTime = 0;
        int maxTaskTime = INT_MIN;
        for(auto vec: logs){
            int taskTime = vec[1] - currTime;
            maxTaskTime = max(maxTaskTime, taskTime);
            if(mp.find(taskTime) == mp.end()){
                mp.insert(make_pair(taskTime, vec[0]));
            } else {
                if(mp[taskTime] > vec[0]){
                    mp[taskTime] = vec[0];
                }
            }
            currTime = vec[1];
        }
        return mp[maxTaskTime];
    }
};