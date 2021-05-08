class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for (auto query : queries) {
        	int centreX = query[0];
        	int centreY = query[1];
        	int radius = query[2];
        	int cnt = 0;

        	for (auto point : points) {
        		int x = point[0];
        		int y = point[1];

        		if (((x - centreX) * (x - centreX)) + ((y - centreY) * (y - centreY)) <= radius * radius)
        			cnt++;
        	}
        	res.push_back(cnt);
        }
        return res;
    }
};
