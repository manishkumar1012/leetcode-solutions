// Problem Link: https://leetcode.com/problems/regular-expression-matching/
// Video Solution: https://www.youtube.com/watch?v=HAA8mgxlov8

class Solution {
public:
	int areMatching(string &s, string &p, int i, int j, vector<vector<int> > &cache) {
		if (i >= s.length() && j >= p.length())
			return 1;
		if (j >= p.length())
			return 0;
        if (cache[i][j] != -1)
			return cache[i][j];
		// no i >= s.length() condition because of cases like "aa", "a*b*"

		int match = i < s.length() && (s[i] == p[j] || p[j] == '.');
		if (j + 1 < p.length() && p[j + 1] == '*') {
			return cache[i][j] = areMatching(s, p, i, j + 2, cache) || (match && areMatching(s, p, i + 1, j, cache));
		}

		if (match)
			return cache[i][j] = areMatching(s, p, i + 1, j + 1, cache);
		return cache[i][j] = 0;
	}

    bool isMatch(string s, string p) {
    	vector<vector<int> > cache(s.length() + 1, vector<int> (p.length() + 1, -1));
        return (bool)areMatching(s, p, 0, 0, cache);
    }
};
