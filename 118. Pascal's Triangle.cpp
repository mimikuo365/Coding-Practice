class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows, vector<int>()); 
        for (int i = 0; i < numRows; i++) {
            pascal[i].resize(i+1);
            if (i == 0) pascal[i] = {1};
            else if (i == 1) pascal[i] = {1, 1};
            else {
                pascal[i][0] = 1;
                for (int j = 1; j < pascal[i-1].size(); j++) {
                    pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
                } 
                pascal[i][pascal[i-1].size()] = 1;
            }
        }
        return pascal;
    }
};
