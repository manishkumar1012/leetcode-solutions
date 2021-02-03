// Problem link: https://leetcode.com/contest/biweekly-contest-40/problems/minimum-number-of-removals-to-make-mountain-array/
// The idea is to find the length of LIS once from left to right and again from right to left.
class Solution {
public:
	// LIS from left to right
	void findListLeft(vector<int>& nums, vector<int>& lisLeft) {
		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					lisLeft[i] = max(lisLeft[i], lisLeft[j] + 1);
				}
			}
		}
	}

	// LIS from right to left
	void findListRight(vector<int>& nums, vector<int>& lisRight) {
		for (int i = nums.size() - 2; i >= 0; i--) {
			for (int j = nums.size() - 1; j > i; j--) {
				if (nums[i] > nums[j]) {
					lisRight[i] = max(lisRight[i], lisRight[j] + 1);
				}
			}
		}
	}

	int minimumMountainRemovals(vector<int>& nums) {
		vector<int> lisLeft(nums.size(), 1), lisRight(nums.size(), 1);
		findListLeft(nums, lisLeft);
		findListRight(nums, lisRight);
		int minmRemovals = nums.size();
		// index 0 can't be a moutain because there is nothing smaller in the left
		// index nums.size() - 1 can't be a moutain because there is nothing larger in the right
		for (int i = 1; i < nums.size() - 1; i++) {
			// an index can be considered as a moutain only if there is at least one smaller in the left
			// and at least one larger in the right
			if (lisLeft[i] > 1 && lisRight[i] > 1)
				minmRemovals = min(minmRemovals, (int)nums.size() - (lisLeft[i] + lisRight[i] - 1));
		}
		return minmRemovals;
	}
};