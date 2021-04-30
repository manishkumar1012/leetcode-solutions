class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> cnt(edges.size() + 2, 0);

        int res, maxCnt = 0;
        for (auto vec : edges) {
        	cnt[vec[0]]++;
        	cnt[vec[1]]++;
        }
        for (int i = 1; i <= edges.size() + 1; i++) {
        	if (cnt[i] > maxCnt) {
        		maxCnt = cnt[i];
        		res = i;
        	}
        }
        return res;
    }
};
