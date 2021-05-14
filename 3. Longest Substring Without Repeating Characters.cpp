class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int start = 0, end = 0, maxLen = 0;
        int counter = 0;
        while (end < s.size()) {
        	if (freq[s[end]] > 0)
        		counter++;
        	freq[s[end]]++;
            end++;
        	while (counter > 0) {
                if (freq[s[start]] > 1)
                    counter--;
                freq[s[start]]--;
                start++;
        	}
            maxLen = max(maxLen, end - start);
        }
        return maxLen;
    }
};
