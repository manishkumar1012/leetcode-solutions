// Problem link: https://leetcode.com/contest/weekly-contest-226/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/

class Solution {
public:
	vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
		vector<long> pref(candiesCount.size() + 1, 0);
		pref[1] = candiesCount[0];
		for (int i = 1; i < candiesCount.size(); i++) {
			pref[i + 1] = pref[i] + candiesCount[i];
		}
		vector<bool> ans;
		for (auto query : queries) {
			long favType = query[0];
			long favDay = query[1];
			long maxCandies = query[2];
			if (pref[favType + 1] < (favDay + 1))
				ans.push_back(false);
			else if ((pref[favType] + 1) > (maxCandies * (favDay + 1)))
				ans.push_back(false);
			else
				ans.push_back(true);
		}
		return ans;
	}
};