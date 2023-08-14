class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int w = 0;
        vector<vector<int>> res;
        while(w < nums.size()){
            if(w > 0 && nums[w] == nums[w-1]){
                w++;
                continue;
            }
            int i = w + 1;
            while(i < nums.size()){
                if(w + 1 != i && nums[i] == nums[i - 1]){
                    i++;
                    continue;
                }
                int j = i + 1;
                int k = nums.size() - 1;
                while(j < k){
                    long long currResult = (long long)nums[w] + (long long)nums[i] + (long long)nums[j] + (long long)nums[k]; 
                    if(currResult == target){
                        res.push_back({nums[w], nums[i], nums[j], nums[k]});
                        j++;
                        k--;
                        while(j < k && nums[j] == nums[j-1]){
                            j++;
                        }
                        while(j < k && nums[k] == nums[k + 1]){
                            k--;
                        }
                    } else if (currResult < target){
                        j++;
                        while(j < k && nums[j] == nums[j - 1]){
                            j++;
                        }
                    } else {
                        k--;
                        while(j < k && nums[k] == nums[k + 1]){
                            k--;
                        }
                    }
                } 
                i++;
            }
            w++;
        }
        return res;
    }
};