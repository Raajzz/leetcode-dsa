#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// vector<vector<int>> threeSum(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     int start = 0;
//     int end = nums.size() - 1;
//     vector<vector<int>> res_vec;
//     auto mid_it = lower_bound(nums.begin(), nums.end(), 0);
//     if(mid_it == nums.begin() || mid_it == nums.end()){
//         return res_vec;
//     }
//     int zero_idx = mid_it - nums.begin();
//     while(start >= end && start != zero_idx && end != zero_idx){
//         if(abs(nums[start]) < abs(nums[end])){
//             for(int i=zero_idx; i<end; i++){
//                 if(nums[start] + nums[end] + nums[i] == 0){
//                     vector<int> new_vec;
//                     new_vec.push_back(nums[start]);
//                     new_vec.push_back(nums[end]);
//                     new_vec.push_back(nums[i]);
//                     res_vec.push_back(new_vec);
//                 }
//             }
//             start++;
//         } else {
//             for(int i=end+1; i<=zero_idx; i++){
//                 if(nums[start] + nums[end] + nums[i] == 0){
//                     vector<int> new_vec;
//                     new_vec.push_back(nums[start]);
//                     new_vec.push_back(nums[end]);
//                     new_vec.push_back(nums[i]);
//                     res_vec.push_back(new_vec);
//                 }
//             }
//             end--;
//         }
//     }
//     return res_vec;
// }

// int main(){
//     vector<int> vec = {-1,0,1,2,-1,-4};
//     for(auto i : threeSum(vec)){
//         for(auto j : i){
//             cout << j << " ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    for(int i=0; i<nums.size(); i++){
        // find two sum only after i
        int start = i;
        int end = nums.size();
        // two sum logic
        int check_num = -nums[i];
        unordered_map<int,pair<int,int>> umap;
        for(int i=start; i<end; i++){
            umap[nums[i]] = make_pair(check_num - nums[i],i);
        }
        for (int i = start; i < end; i++){
            pair<int,int> umap_nums_i = umap[nums[i]];
            pair<int,int> umap_umap = umap[umap[nums[i]].first];
            if(nums[i] == umap_umap.first && umap_nums_i.second != umap_umap.second){
                res.push_back({umap_nums_i.first, nums[i], -check_num});
            }
        }    
    }
    return res;
}

int main(){
    vector<int> vec = {-1,0,1,2,-1,-4};
    for(auto i : threeSum(vec)){
        for(auto j : i){
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}