class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto val : nums){
            pq.push(val);            
        }
        int res;
        while(k--){
            res = pq.top();
            pq.pop();
        }
        return res;
    }
};