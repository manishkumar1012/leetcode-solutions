// Problem link: https://leetcode.com/problems/delete-operation-for-two-strings/

/*
    base case
    if (i >= length of word1)
        return (length of word2 - j);
    else if (j >= length of word2)
        return (length of word1 - i);
        
    recursion
    if (same)
        (i + 1, j + 1)
    else
        min((i + 1, j), (i, j + 1));
    
    
*/

class Solution {
public:
    int minDeletions(int i, int j, string &word1, string &word2, vector<vector<int> > &cache) {
    	if (i >= word1.length())
    		return word2.length() - j;
    	else if (j >= word2.length())
    		return word1.length() - i;

    	if (cache[i][j] != -1)
    		return cache[i][j];

    	if (word1[i] == word2[j])
    		cache[i][j] = minDeletions(i + 1, j + 1, word1, word2, cache);
    	else 
    		cache[i][j] = 1 + min(minDeletions(i + 1, j, word1, word2, cache), minDeletions(i, j + 1, word1, word2, cache));
    	return cache[i][j];
    }

    
    int minDistance(string word1, string word2) {
        vector<vector<int> > cache(word1.length() + 1, vector<int> (word2.length() + 1, -1));
        return minDeletions(0, 0, word1, word2, cache);
    }
};

