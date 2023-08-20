class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        int i = 0;
        int z = 0;
        vector<string> vec(numRows, "");
        int shouldIterateOver = numRows - 1;
        while(z < s.size()){
            if(i % shouldIterateOver == 0){
                for(int k = 0; k < numRows && z < s.size(); k++){
                    vec[k] += s[z++];
                }
            } else {
                vec[shouldIterateOver - i % shouldIterateOver] += s[z++];
            }
            i++;
        }
        z = 0;
        for(int i=0; i<numRows; i++){
            for(int j = 0; j<vec[i].size(); j++){
                s[z++] = vec[i][j];
            }
            cout << " ";
        }
        return s;
    }
};