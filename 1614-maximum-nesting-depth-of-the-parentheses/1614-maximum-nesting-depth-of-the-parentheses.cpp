class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = INT_MIN;
        int depth = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                depth++;
            }
            maxDepth = max(maxDepth, depth);
            if(s[i] == ')'){
                depth--;
            }
        }
        return maxDepth;
    }
};