class Solution {
public:
    vector<int> generateRow(int row) {
        long long res = 1 ;
        vector<int> ansRow;
        ansRow.push_back(1) ;
        for(int col = 1 ; col < row ; col++) {
            res =  res * ( row - col) ;
            res = res / col ;
            ansRow.push_back(res) ;
        }
        return ansRow ;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans ;
        for(int i = 1 ; i <= numRows ; i++) {
            ans.push_back(generateRow(i)) ;
        }
        return ans ;
    }
};