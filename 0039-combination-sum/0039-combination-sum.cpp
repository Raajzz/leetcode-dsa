class Solution {
public:
    void combinations(vector<int> &vec, int target, vector<vector<int>> &res, vector<int> currVec, int index, int currSum){
        if(currSum > target){
            return;
        }
        if(index >= vec.size()){
            if(currSum == target){
                res.push_back(currVec);
            }
            return;
        }
        // take
        currVec.push_back(vec[index]); currSum += vec[index];
        combinations(vec, target, res, currVec, index, currSum);
        // not take
        currVec.pop_back(); currSum -= vec[index];
        combinations(vec, target, res, currVec, index + 1, currSum);
    }
    
    vector<vector<int>> combinationSum(vector<int>& vec, int target) {
        vector<vector<int>> res;
        vector<int> currVec;
        int currSum = 0;
        int index = 0;
        combinations(vec, target, res, currVec, index, currSum);
        return res;
    }
};