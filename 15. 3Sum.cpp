// Problem link: https://leetcode.com/problems/3sum/
// Handle duplicates with care

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
        	int target = -nums[i];
        	int j = i + 1;
        	int k = n - 1;

        	while (j < k) {
        		int sum = nums[j] + nums[k];
        		if (sum < target)
        			j++;
        		else if (sum > target)
        			k--;
        		else {
        			vector<int> triplet = {nums[i], nums[j++], nums[k--]};
        			res.push_back(triplet);

        			while (j < k && nums[j] == triplet[1])
        				j++;

        			while (j < k && nums[k] == triplet[2])
        				k--;
        		}
        	}

        	while (i + 1 < n && nums[i + 1] == nums[i])
        		i++;
        }
        return res;
    }
};
