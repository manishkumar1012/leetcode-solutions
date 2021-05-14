/*
    very useful link for sliding window problems: https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
*/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        for (auto ch : t)
        	freq[ch]++;

        int start = 0, end = 0, minStart = 0, minLen = s.size() + 1;
        int counter = t.size();
        while (end < s.size()) {
        	if (freq[s[end]] > 0)
        		counter--;
        	freq[s[end]]--;
            end++;
        	while (!counter) {
        		if ((end - start) < minLen) {
                    minStart = start;
        			minLen = end - start;
        		}
                
                freq[s[start]]++;
                if (freq[s[start]] > 0)
                    counter++;
                start++;
        	}
        }
        if (minLen == s.size() + 1)
        	return "";
        return s.substr(minStart, minLen);
    }
};

/*
string minWindow(string s, string t) {
	unordered_map<char, int> m;
	// Statistic for count of char in t
	for (auto c : t) m[c]++;
	// counter represents the number of chars of t to be found in s.
	size_t start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
	size_t size = s.size();
	
	// Move end to find a valid window.
	while (end < size) {
		// If char in s exists in t, decrease counter
		if (m[s[end]] > 0)
			counter--;
		// Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
		m[s[end]]--;
		end++;
		// When we found a valid window, move start to find smaller window.
		while (counter == 0) {
			if (end - start < minLen) {
				minStart = start;
				minLen = end - start;
			}
			m[s[start]]++;
			// When char exists in t, increase counter.
			if (m[s[start]] > 0)
				counter++;
			start++;
		}
	}
	if (minLen != INT_MAX)
		return s.substr(minStart, minLen);
	return "";
}
*/
