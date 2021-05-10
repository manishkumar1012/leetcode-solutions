/*
	[[1, 4], [2, 8], [9, 12], [10, 11], [34, 56]]
	[[1, 8], [9, 12], [34, 56]]

	prevStart, prevEnd
	// overlap
	if (currStart <= prevEnd) {
		prevEnd = max(prevEnd, currEnd);
	} else { // no overlap
		res.push_back({prev});
		prev = curr;
	}

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());

        int prevStart = intervals[0][0];
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if (currStart <= prevEnd)
                prevEnd = max(prevEnd, currEnd);
            else {
                res.push_back({prevStart, prevEnd});
                prevStart = currStart;
                prevEnd = currEnd;
            }
        }
        res.push_back({prevStart, prevEnd});
        return res;
    }
};
