// Problem Link: https://leetcode.com/problems/surrounded-regions/

// Idea : Using DFS to traverse the boundaries, when 'O' is found, fire the dfs() to flip all the connected 'O' into ' * '.
// After that, go through the board and flip the other 'O' to 'X', since these 'O' cannot escape the board. Then flip all the '*' to 'O', indicating these 'O' can reach out of the board.

class Solution {
public:
	void dfs(int i, int j, vector<vector<char>>& board) {
        // don't consider border row and column
		if (i <= 0 || j <= 0 || i >= board.size() - 1 || j >= board[0].size() - 1)
			return;
		if (board[i][j] == 'X' || board[i][j] == '*')
			return;

		if (board[i][j] = 'O')
            board[i][j] = '*';

		dfs(i + 1, j, board);
		dfs(i - 1, j, board);
		dfs(i, j + 1, board);
		dfs(i, j - 1, board);
	}
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // first and last row
        for (int i = 0; i < n; i++) {
            // don't call dfs on 1st row
        	if (board[0][i] == 'O')
        		dfs(1, i, board); 
        	if (board[m - 1][i] == 'O')
        		dfs(m - 2, i, board);
        }

        // first and last column
        for (int i = 0; i < m; i++) {
            // don't call dfs on 1st column
        	if (board[i][0] == 'O')
        		dfs(i, 1, board);
        	if (board[i][n - 1] == 'O')
        		dfs(i, n - 2, board);
        }

        // flip O to X, '*' to 'O',
        // skip the boulders
        for (int i = 1; i < m - 1; i++) {
        	for (int j = 1; j < n - 1; j++) {
        		if (board[i][j] == 'O')
        			board[i][j] = 'X';
        		else if (board[i][j] == '*')
        			board[i][j] = 'O';
        	}
        }
        return;
    }
};
