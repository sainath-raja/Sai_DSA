class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlen = 0;
        for(int i = 0; i < n; i++){
            int hash[256] = {0};
            for(int j = i; j < n; j++){
                if(hash[s[j]] == 1){
                    break;
                }
                hash[s[j]] = 1; 
                maxlen = max(maxlen, j - i + 1);
            }
            
            
        }
        return maxlen;
    }
};