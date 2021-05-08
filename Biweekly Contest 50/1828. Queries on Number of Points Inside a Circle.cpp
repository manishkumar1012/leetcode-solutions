// Brute Force Solution
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

// Optimized Solution
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        
        sort(points.begin(), points.end());
        for (auto query : queries) {
        	int centreX = query[0];
        	int centreY = query[1];
        	int radius = query[2];
        	int cnt = 0;

        	int ind = lower_bound(points.begin(), points.end(), vector<int>{centreX - radius, 0}) - points.begin();

        	for (; ind < points.size(); ind++) {
                auto point = points[ind];
        		int x = point[0];
        		int y = point[1];
        		if (x > centreX + radius)
        			break;

        		if (((x - centreX) * (x - centreX)) + ((y - centreY) * (y - centreY)) <= radius * radius)
        			cnt++;
        	}
        	res.push_back(cnt);
        }
        return res;
    }
};
