class Solution {
public:
    void reverseString(vector<char>& s) {
        int s_size = s.size();
        for(int i=0; i<s.size()/2; i++){
            swap(s[i], s[s_size-1-i]);
        }
    }
};