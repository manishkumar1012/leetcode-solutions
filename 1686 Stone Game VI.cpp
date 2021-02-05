// Problem Link: https://leetcode.com/contest/biweekly-contest-41/problems/stone-game-vi/

class Solution {
public:
	int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
		int n = aliceValues.size();
		vector<pair<int, int> > valuesSum(n);
		for (int i = 0; i < n; i++)
			valuesSum[i] = make_pair(aliceValues[i] + bobValues[i], i);
		sort(valuesSum.begin(), valuesSum.end(), greater<pair<int, int> >());
		int alicePts = 0, bobPts = 0;
		for (int i = 0; i < n; i++) {
			int idx = valuesSum[i].second;
			if (i % 2)
				bobPts += bobValues[idx];
			else
				alicePts += aliceValues[idx];
		}
		if (alicePts > bobPts)
			return 1;
		else if (alicePts < bobPts)
			return -1;
		return 0;
	}
};