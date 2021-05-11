class Solution {
private: 
    // since the string only contains lowercase characters, we can use radix sort to improve time complexity.
	string radixSort(string str) {
		int count[26] = {0};
		for (auto ch : str)
			count[ch - 'a']++;
		string sortedStr = "";
		for (int i = 0; i < 26; i++) 
			sortedStr += string(count[i], i + 'a');
		return sortedStr;
	}

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        unordered_map<string, vector<string>> mp;
        for (auto str: strs) {
        	mp[radixSort(str)].push_back(str);
        }

        for (auto p: mp) {
        	anagrams.push_back(p.second);
        }
        return anagrams;
    }
};
