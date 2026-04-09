class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int t = 0, b = n - 1;

        while(t <= b){
            int mid = t + (b - t) / 2;

            if(target < matrix[mid][0])
                b = mid - 1;
            else if(target > matrix[mid][m - 1])
                t = mid + 1;
            else
                break;            
        }

        if(!(t <= b))
            return false;

        int row = t + (b - t) / 2;

        int l = 0, r = m - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            
            if(target == matrix[row][mid])
                return true;
            else if(target < matrix[row][mid])
                r = mid - 1;
            else
                l = mid + 1;
        }

        return false;
    }
};
