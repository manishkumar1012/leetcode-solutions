class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        
        int top = 0; // starting row index
        int bottom = m - 1; // ending row index
        int left = 0; // starting column index
        int right = n - 1; // ending column index

        while (top <= bottom && left <= right) {
        	// print top row
        	for (int col = left; col <= right; col++) 
        		res.push_back(matrix[top][col]);
        	top++;

        	// print right column
        	for (int row = top; row <= bottom; row++) 
        		res.push_back(matrix[row][right]);
        	right--;

        	if (top <= bottom) {
	        	// print bottom row
	        	for (int col = right; col >= left; col--) 
	        		res.push_back(matrix[bottom][col]);
	        	bottom--;
	        }

	        if (left <= right) {
	        	// print left column
	        	for (int row = bottom; row >= top; row--)
	        		res.push_back(matrix[row][left]);
	        	left++;
	        }
        }
        return res;
    }
};
