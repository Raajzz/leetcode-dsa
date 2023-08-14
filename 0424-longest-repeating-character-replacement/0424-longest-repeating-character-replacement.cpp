class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> frequencyMap(26, 0);
        int left = 0;
        int right = 0;
        int res = INT_MIN;
        int mostFreq = 0;
        while(right < s.size()){
            frequencyMap[s[right] - 'A']++;
            mostFreq = max(mostFreq, frequencyMap[s[right] - 'A']);
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