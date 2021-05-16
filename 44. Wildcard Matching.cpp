/*
    abdca, a*c?
    
    // base cases
    if (both are out of bounds)
        return true;
        
    if (i >= s.length()) {
        return p[j] == '*' && match(i, j + 1);
    }
    
    if (j is out of bounds)
        return false;
    
    if (cache[i][j] != -1)
        return cache[i][j];
        
    // recursion
    
    if (s[i] == p[j] || p[j] == '?'),
        return match(i + 1, j + 1);
    
    // if p[j] is '*'
    do not use *
    match(i, j + 1);
    
    use *
    match(i + 1, j);
    
    else 
        return false;

*/

class Solution {
private:
	int match(int i, int j, string& s, string& p, vector<vector<int>>& cache) {
		if (i == s.length() && j == p.length())
			return 1;
		if (j == p.length())
			return false;
		if (i == s.length()) 
			return p[j] == '*' && match(i, j + 1, s, p, cache);
        if (cache[i][j] != -1)
            return cache[i][j];

		if (s[i] == p[j] || p[j] == '?')
			cache[i][j] = match(i + 1, j + 1, s, p, cache);
		else if (p[j] == '*') {
			cache[i][j] = match(i, j + 1, s, p, cache) || match(i + 1, j, s, p, cache);
		} else {
			cache[i][j] = 0;
		}

		return cache[i][j];
	}

public:
    bool isMatch(string s, string p) {
        vector<vector<int>> cache(s.length(), vector<int>(p.length(), -1));
        return match(0, 0, s, p, cache);
    }
};
