#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

static int max_val =  0;

void find_max(vector<int>& nums, int idx, int max_till, unordered_map<int,int> &umap){
    if(idx >= nums.size()){
        if(max_till > max_val){
            max_val = max_till;
        }
    } else {
        if(umap[idx] != 0){
            find_max(nums, nums.size(), max_till + umap[idx], umap);
        } else {
            for(int i=idx; i<nums.size();i++){
                find_max(nums, i + 2, max_till + nums[i], umap);
                umap[idx] = max_val;
            }
        }
    }
}

int main(){
    vector<int> val = ;
    unordered_map<int,int> umap;
    find_max(val, 0, 0, umap);
    cout << max_val << "\n";
}