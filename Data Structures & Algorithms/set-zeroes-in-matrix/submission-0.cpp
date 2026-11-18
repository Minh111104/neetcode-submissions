// Time: O(m*n)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> row;     // using set to store all 0
        unordered_set<int> col;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        // iterate again to set the row and col to 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row.count(i) || col.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};