class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> magArray(26, 0);
        for(auto mag: magazine){
            magArray[mag - 'a'] += 1;
        }
        for(auto note: ransomNote){
            magArray[note - 'a'] -= 1;
            if(magArray[note - 'a'] < 0){
                return false;
            }
        }
        return true;
    }
};