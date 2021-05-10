/*
    Problem Link: https://leetcode.com/problems/set-matrix-zeroes/
    Solution Link: https://leetcode.com/problems/set-matrix-zeroes/solution/
    
    can't use extra space so utilize the first row and first column as flag.
    matrix[0][0] denotes both first row and first column, so use that to denote only one (say first row).
    and use a variable to check for the first column.

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int isFirstColZero = 0;

        for (int i = 0; i < m; i++) {
            if (!matrix[i][0])
                isFirstColZero = 1;
        	for (int j = 1; j < n; j++) {
        		if (!matrix[i][j]) {
        			matrix[0][j] = 0;
        			matrix[i][0] = 0;
        		}
        	}
        }

        for (int i = 1; i < m; i++) {
        	for (int j = 1; j < n; j++) {
        		if (!matrix[i][0] || !matrix[0][j]) 
        			matrix[i][j] = 0;
        	}
        }

        if (!matrix[0][0]) {
        	for (int j = 0; j < n; j++)
        		matrix[0][j] = 0;
        }

        if (isFirstColZero) {
        	for (int i = 0; i < m; i++) 
        		matrix[i][0] = 0;
        }
    }
};
