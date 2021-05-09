class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int usedRow[9][9] = {0};
        int usedCol[9][9] = {0};
        int usedBox[9][9] = {0};

        for (int i = 0; i < 9; i++) {
        	for (int j = 0; j < 9; j++) {
        		if (board[i][j] != '.') {
        			int currVal = board[i][j] - '0' - 1;
        			int boxNo = (i / 3) * 3 + (j / 3);

        			if (usedRow[i][currVal] || usedCol[j][currVal] || usedBox[boxNo][currVal])
        				return false;
        			usedRow[i][currVal] = usedCol[j][currVal] = usedBox[boxNo][currVal] = 1;
        		}
        	}
        }
        return true;
    }
};
