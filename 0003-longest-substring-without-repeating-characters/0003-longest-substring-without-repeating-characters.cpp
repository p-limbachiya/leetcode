class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> seen(256,-1);
        int l=0,ans=0;
        for(int r=0; r<s.size(); r++){
            if(seen[s[r]] >= l){
                l = seen[s[r]] + 1;
            }
            seen[s[r]] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};