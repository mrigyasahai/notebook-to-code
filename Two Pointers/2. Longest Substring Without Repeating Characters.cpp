class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, len = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            int hash[256]={0};
            for(int j = i;j<n;j++){
                if(hash[s[j]]==1) break;
                len = j - i + 1;
                maxLen = max(maxLen, len);
                hash[s[j]]=1;
            }
        }
        return maxLen;
    }
};
