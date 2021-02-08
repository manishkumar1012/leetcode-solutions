// Problem link: https://leetcode.com/contest/weekly-contest-226/problems/palindrome-partitioning-iv/

class Solution {
public:
	bool checkPartitioning(string s) {
		int n = s.length();
		vector<vector<int> > isPal(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			isPal[i][i] = 1;
		}
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == s[i + 1])
				isPal[i][i + 1] = 1;
		}
		for (int len = 3; len <= n; len++) {
			for (int i = 0; i <= n - len; i++) {
				int j = i + len - 1;
				if (s[i] == s[j] && isPal[i + 1][j - 1])
					isPal[i][j] = 1;
			}
		}
		for (int i = 1; i < n - 1; i++) {
			for (int j = i; j < n - 1; j++) {
				if (isPal[0][i - 1] && isPal[i][j] && isPal[j + 1][n - 1])
					return true;
			}
		}
		return false;
	}
};