class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // using min heap
        // this data-structure will always have the 'k' largest elements at the end of vector insertion, who's top will be the kth-largest element
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto val : nums){
            pq.push(val);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};