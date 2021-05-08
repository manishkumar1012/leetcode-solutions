/*
    Problem link: https://leetcode.com/problems/generate-parentheses/
    
    no. of closing brackets must always be <= no. of opening brackets
    
    base case
    if (open == n && close == n)
        print the string formed and return;
    
    
    if (open < n)
        (open + 1, close, str + '(');
    if (close < n && close < open)
        (open, close + 1, str + ')');

*/

class Solution {
public:
	void getValidParenthesis(int open, int close, int n, string str, vector<string> &validParenthesis) {
		if (open == n && close == n) {
			validParenthesis.push_back(str);
			return;
		}

		if (open < n)
			getValidParenthesis(open + 1, close, n, str + '(', validParenthesis);
		if (close < n && close < open)
			getValidParenthesis(open, close + 1, n, str + ')', validParenthesis);
		return;
	}

    vector<string> generateParenthesis(int n) {
        vector<string> validParenthesis;
        getValidParenthesis(0, 0, n, "", validParenthesis);
        return validParenthesis;
    }
};
