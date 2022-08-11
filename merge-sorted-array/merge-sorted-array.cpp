class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // swapping solution, not working properly for cases where the nums2 stuff needs to be inserted in the middle of num1
        // int ptr_1 = 0;
        // int ptr_2 = 0;
        // int ptr_3 = m;
        // while(ptr_1 < m && ptr_2 < n){
        //     if(nums1[ptr_1] > nums2[ptr_2]){
        //         swap(nums1[ptr_1], nums1[ptr_3]);
        //         nums1[ptr_1] = nums2[ptr_2];
        //         ptr_3++;
        //         ptr_2++;
        //         ptr_1++;
        //         m++;
        //     } else {
        //         ptr_1++;
        //     }
        // }
        // if(ptr_3 < m+n){
        //     while(ptr_2 < n){
        //         nums1[ptr_3] = nums2[ptr_2];
        //         ptr_3++;
        //         ptr_2++;
        //     }
        // }
        
        // using auxillary space
        vector<int> new_vec;
        new_vec.reserve(m);
        for(int i=0; i<m; i++){
            new_vec.push_back(nums1[i]);
        }
        int ptr_1 = 0;
        int ptr_2 = 0;
        int res_counter = 0;
        while(ptr_1 < m && ptr_2 < n){
            if(new_vec[ptr_1] <= nums2[ptr_2] ){
                nums1[res_counter] = new_vec[ptr_1];
                ptr_1++;
                res_counter++;
            } else {
                nums1[res_counter] = nums2[ptr_2];
                ptr_2++;
                res_counter++;
            }
        }
        while(ptr_1 < m){
            nums1[res_counter] = new_vec[ptr_1];
            ptr_1++;
            res_counter++;
        }
        while(ptr_2 < n){
            nums1[res_counter] = nums2[ptr_2];
            ptr_2++;
            res_counter++;
        }
    }
};