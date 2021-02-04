class Solution {
public:
	int countConsistentStrings(string allowed, vector<string>& words) {
		unordered_map<int, int> mp;
		for (auto ch : allowed)
			mp[ch] = 1;
		int numOfConsistent = 0;
		for (auto str : words) {
			int flag = 1;
			for (auto ch : str) {
				if (!mp.count(ch)) {
					flag = 0;
					break;
				}
			}
			if (flag)
				numOfConsistent++;
		}
		return numOfConsistent;
	}
};