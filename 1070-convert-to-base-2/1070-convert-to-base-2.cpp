class Solution {
public:
    string baseNeg2(int n) {
        if(n==0) return "0";
        string ans;
        while(n!=0){
            int bit = n % -2;
            n = n/-2;
            if(bit<0){
                bit+=2;
                n+=1;
            }
            ans.push_back('0'+ bit);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};