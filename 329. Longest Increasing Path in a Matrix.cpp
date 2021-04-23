// Problem Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
public:
	int diffRow[4] = {-1, 0, 1, 0};
	int diffCol[4] = {0, 1, 0, -1};

	bool isValidMove(int i, int j, int m, int n) {
		if (i < m && j < n && i >= 0 && j >= 0)
			return true;
		return false;
	}

	int computeLIPLength(int currRow, int currCol, vector<vector<int>>& matrix, vector<vector<int> > &LIPLength) {
		if (LIPLength[currRow][currCol] != -1)
			return LIPLength[currRow][currCol];
		int maxm = 1;
		for (int i = 0; i < 4; i++) {
			int nextRow = currRow + diffRow[i];
			int nextCol = currCol + diffCol[i];
			if (!isValidMove(nextRow, nextCol, matrix.size(), matrix[0].size()))
				continue;
			if (matrix[nextRow][nextCol] > matrix[currRow][currCol]) {
				maxm = max(maxm, 1 + computeLIPLength(nextRow, nextCol, matrix, LIPLength));
			}
		}
		return LIPLength[currRow][currCol] = maxm;
	}

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 1;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int> > LIPLength(m, vector<int> (n, -1));
        for (int i = 0; i < m; i++) {
        	for (int j = 0; j < n; j++) {
                if (LIPLength[i][j] == -1)
                    computeLIPLength(i, j, matrix, LIPLength);
        	}
        }
        for (int i = 0; i < m; i++) {
        	for (int j = 0; j < n; j++) {
        		res = max(res, LIPLength[i][j]);
        	}
        }
        return res;
    }
};
