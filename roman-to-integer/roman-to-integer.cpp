class Solution {
public:
    int romanToInt(string str) {
        unordered_map<char, int> umap;
        // I             1
        // V             5
        // X             10
        // L             50
        // C             100
        // D             500
        // M             1000
        
        umap['I'] = 1;
        umap['V'] = 5;
        umap['X'] = 10;
        umap['L'] = 50;
        umap['C'] = 100;
        umap['D'] = 500;
        umap['M'] = 1000;
        
        int num = 0;
        
        for(int i=0; i<str.size(); i++){
            if(umap[str[i]] >= umap[str[i+1]]){
                num += umap[str[i]];
            } else {
                num += -(umap[str[i]]);
            }
        }
        
        return num;
    }
};