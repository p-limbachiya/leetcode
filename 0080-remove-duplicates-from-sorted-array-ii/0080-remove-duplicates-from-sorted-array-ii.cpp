class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            int num = nums[j];
            if (i < 2 || nums[i - 2] != num) {
                nums[i] = num;
                i++;
            }
        }
        return i;
    }
};