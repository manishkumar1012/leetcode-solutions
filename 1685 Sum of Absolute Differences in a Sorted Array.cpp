class Solution {
public:
	vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
		int n = nums.size();
		int totalSum = accumulate(nums.begin(), nums.end(), 0);
		vector<int> absDiff(n);
		int currSum = 0;
		for (int i = 0; i < n; i++) {
			currSum += nums[i];
			absDiff[i] = ((i + 1) * nums[i]) - currSum) + abs((totalSum - currSum) - ((n - i - 1) * nums[i]));
		}
		return absDiff;
	}
};