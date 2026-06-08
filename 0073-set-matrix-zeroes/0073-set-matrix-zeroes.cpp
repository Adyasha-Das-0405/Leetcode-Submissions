class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Your code goes here
        int m = matrix.size(), n = matrix[0].size() ;

        int colvar = 1 ;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++) {
                if(matrix[i][j] == 0) {
                    //mark i-th row
                    matrix[i][0] = 0 ;
                    //mark j=th col
                    if(j != 0){
                        matrix[0][j] = 0 ;
                    } else {
                        colvar = 0 ;
                    }
                }
            }
        }

        for(int i = 1 ; i < m ; i++) {
            for(int j = 1 ; j < n ; j++) {
                if(matrix[i][j] != 0) {
                    if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0 ;
                    }
                }
            }
        }
        if(matrix[0][0] == 0){
            for(int j = 0 ; j < n ; j++) matrix[0][j] = 0 ;
        }
        if(colvar == 0) {
            for(int i = 0 ; i < m ; i++) {
                matrix[i][0] = 0 ;
            }
        }
    }
};