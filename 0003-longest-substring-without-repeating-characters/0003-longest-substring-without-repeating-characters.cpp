class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ssize = s.size();
        if(ssize == 0) return 0;
        int ans = 0,l=0,r=0;
        unordered_map<char,int> check;
        while (r < ssize){
            if(check[s[r]] == 0){
                check[s[r]] += 1;
                r++;
                ans = max(ans,r-l);
            }else if(check[s[r]] == 1){
                while(s[l]!=s[r]){
                    check[s[l]]--;
                    l++;
                }
                check[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};