class Solution {
public:
    int strStr(string haystack, string needle) {
        // needle should be lesser
        // haystack should be larger
        
        // using z algorithm
        if(needle.size() == 0){
            return 0;
        }
        if(haystack.size() >= needle.size()){
            char spec_char = '$';
            int need_size = needle.size();
            int hay_size = haystack.size();
            needle += spec_char + haystack;
            int tot_size = needle.size();
            vector<int> z_array(tot_size, 0);
            int i = 0;
            int j = need_size + 1;
            int k = 0;
            int res_idx = 0;
            while(j<tot_size){
                k = j;
                while(needle[i] != spec_char && needle[i] == needle[j]){
                    i++;
                    j++;
                }
                z_array[k] = i;
                if(z_array[k] == need_size){
                    return k - need_size - 1;
                }
                i = 0;
                j = k;
                j++;
            }
        } 
        return -1;
    }
};