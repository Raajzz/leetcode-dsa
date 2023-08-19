class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> freqTable;
        
        // tokenization
        string token = "";
        for(auto chr: paragraph){
            if((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z')){
                token += tolower(chr);
            } else if(token.size() > 0) {
                freqTable[token]++;
                token = "";
            }
        }
        if(token.size() > 0){        
            freqTable[token]++;
        }
        for(auto str: banned){
            freqTable[str] = 0;
        }
        freqTable[token]++;
        string res;
        int maxCount = INT_MIN;
        for(auto mapPair: freqTable){
            if(mapPair.first.size() > 0 && mapPair.second >= maxCount){
                res = mapPair.first;
                maxCount = mapPair.second;
            }
        }
        return res;
    }
};