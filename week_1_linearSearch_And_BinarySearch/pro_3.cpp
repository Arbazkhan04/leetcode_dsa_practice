class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int outer = 0; outer < matrix.size(); outer++) {
            int si = 0;
            int ei = matrix[outer].size() - 1;
            
            while (si <= ei) {
                int mid = si + (ei - si) / 2;
                
                if (matrix[outer][mid] == target) {
                    return true;
                } else if (matrix[outer][mid] < target) {
                    si = mid + 1;
                } else {
                    ei = mid - 1;
                }
            }
        }
        
        return false;
    }
};
