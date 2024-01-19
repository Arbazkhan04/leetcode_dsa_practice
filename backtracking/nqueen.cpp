class Solution {
public:
    int n;
    int totalNQueens(int n) {
        this->n = n;
        unordered_set<int> col;
        unordered_set<int> diagonal;
        unordered_set<int> antidiagonal;
        return backtrack(0,diagonal,antidiagonal,col);
    }
    int backtrack(int row,unordered_set<int>& diagonal,unordered_set<int>& antidiagonal,unordered_set<int>& cols){
        {
            if(row==n){
                return 1;
            }
            int solution =0;
            for(int col=0;col<n;col++){
                int currdg = row - col;
                int currantidp = row+col;
                if(cols.find(col)!=cols.end() || diagonal.find(currdg)!=diagonal.end() || antidiagonal.find(currantidp)!=antidiagonal.end()){
                    continue;
                }
                cols.insert(col);
                diagonal.insert(currdg);
                antidiagonal.insert(currantidp);
                solution+=backtrack(row+1,diagonal,antidiagonal,cols);
                cols.erase(col);
                diagonal.erase(currdg);
                antidiagonal.erase(currantidp);
            }
            return solution;
        }
    }
};