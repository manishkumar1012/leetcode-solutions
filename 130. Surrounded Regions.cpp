// // Problem Link: https://leetcode.com/problems/surrounded-regions/

// // Idea : Using DFS to traverse the boundaries, when 'O' is found, fire the dfs() to flip all the connected 'O' into ' * '.
// // After that, go through the board and flip the other 'O' to 'X', since these 'O' cannot escape the board. Then flip all the '*' to 'O', indicating these 'O' can reach out of the board.

class Solution {
public:
	void dfs(int i, int j, vector<vector<char>>& board) {
		if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
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
        	if (board[0][i] == 'O')
        		dfs(0, i, board); 
        	if (board[m - 1][i] == 'O')
        		dfs(m - 1, i, board);
        }

        // first and last column
        for (int i = 0; i < m; i++) {
        	if (board[i][0] == 'O')
        		dfs(i, 0, board);
        	if (board[i][n - 1] == 'O')
        		dfs(i, n - 1, board);
        }

        // flip O to X, '*' to 'O',
        for (int i = 0; i < m; i++) {
        	for (int j = 0; j < n; j++) {
        		if (board[i][j] == 'O')
        			board[i][j] = 'X';
        		else if (board[i][j] == '*')
        			board[i][j] = 'O';
        	}
        }
        return;
    }
};
