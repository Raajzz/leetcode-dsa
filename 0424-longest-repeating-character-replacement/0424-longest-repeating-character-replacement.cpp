class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> frequencyMap(26, 0);
        int left = 0;
        int right = 0;
        int res = INT_MIN;
        while(right < s.size()){
            frequencyMap[s[right] - 'A']++;
            int mostFreq = 0;
            for(int i=0; i<frequencyMap.size(); i++){
                mostFreq = max(mostFreq, frequencyMap[i]);
            }
            if(right - left + 1 - mostFreq <= k){
                res = max(res, right - left + 1);
            } else {
                frequencyMap[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return res;
    }
};