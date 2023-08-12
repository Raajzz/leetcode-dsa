class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        
        int tempCounterI = 0;
        int tempCounterJ = 0;
        while(i >= 0 && j >= 0){
            tempCounterI = 0;
            tempCounterJ = 0;
            
            while(i >= 0 && (s[i] == '#' || tempCounterI > 0)){
                if(s[i] == '#'){
                    tempCounterI++;
                } else {
                    tempCounterI--;
                }
                i--;
            }
            
            while(j >= 0 && (t[j] == '#' || tempCounterJ > 0)){
                if(t[j] == '#'){
                    tempCounterJ++;
                } else {
                    tempCounterJ--;
                }
                j--;
            }
            
            if(i == -1 || j == -1 || s[i] != t[j]){
                break;
            }
            
            i--;
            j--;
        }

        while(i >= 0 && (s[i] == '#' || tempCounterI > 0)){
            if(s[i] == '#'){
                tempCounterI++;
            } else {
                tempCounterI--;
            }
            i--;
        }

        while(j >= 0 && (t[j] == '#' || tempCounterJ > 0)){
            if(t[j] == '#'){
                tempCounterJ++;
            } else {
                tempCounterJ--;
            }
            j--;
        }
        
        return (i == -1 && j == -1);
    }
};