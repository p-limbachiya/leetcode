class Solution {
public:
    int maxelement(vector<vector<int>>& mat,int col){
        int max = -1;
        int index = -1;
        int n=mat.size();
        for(int i =0; i< n;i++){
            if(mat[i][col]>max){
                max = mat[i][col];
                index = i;
            } 
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0;
        vector<int> ans;
        int n = mat[0].size();
        int high = n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row= maxelement(mat,mid);
            int left = mid-1 >= 0 ? mat[row][mid-1] : -1;
            int right = mid+1 < n ? mat[row][mid+1] : -1; 
            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row,mid};
            } 
            else if(mid+1 < n && mat[row][mid] > mat[row][mid+1]) high=mid-1;
            else low=mid+1;
        }
        return ans;
    }
};