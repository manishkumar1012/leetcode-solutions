// Problem link: https://leetcode.com/problems/container-with-most-water/
// Idea: area = distance * minHeight so maximize minHeight as distance decreases.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int res = 0;
        int left = 0, right = n - 1;

        while (left < right) {
        	int minh = min(height[left], height[right]);
        	res = max(res, minh * (right - left));

        	while (left < right && height[left] <= minh)
        		left++;

			while (right > left && height[right] <= minh)
        		right--;        	
        }
        return res;
    }
};
